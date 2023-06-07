#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a, b, k;
int primes[N], cnt;
bool st[N];

int ps[N];

void get_primes(int n) {
    for(int i = 2; i <= n; i ++) {
        if(!st[i]) primes[cnt ++ ] = i;
        for(int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }

    st[1] = st[0] = true; // 非质数
    for(int i = 1; i <= b; i ++) {
        ps[i] = ps[i - 1] + (st[i] == false);
    }
}

bool check(int X) {
    if(!X) return false;
    for(int i = a; i + X - 1 <= b; i ++) {
        if(ps[i + X - 1] - ps[i - 1] < k) return false;
    }

    return true;
}

int main() {
    scanf("%d%d%d", &a, &b, &k);
    get_primes(b);

    int l = 0, r = min(N, b - a + 1);
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    if(!check(r)) r = -1;

    cout << r << "\n";
    return 0;
}