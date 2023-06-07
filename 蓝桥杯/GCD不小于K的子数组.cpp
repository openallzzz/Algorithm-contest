#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010, M = 20;

int n, m, k;
int a[N];
int f[N][M];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    k = log(n) / log(2);
    for(int j = 0; j <= k; j ++) {
        for(int i = 0; i + (1 << j) - 1 < n; i ++) {
            if(!j) f[i][j] = a[i];
            else {
                int l = f[i][j - 1], r = f[i + (1 << j - 1)][j - 1];
                f[i][j] = gcd(l, r);
            }
        }
    }

    // 初始化ST表结束

    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        int l = i, r = n - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(query(i, mid) >= m) l = mid;
            else r = mid - 1;
        }
        if(r >= i && query(i, r) >= m) ans += (r - i + 1);
    }

    printf("%lld\n", ans);
    return 0;
}