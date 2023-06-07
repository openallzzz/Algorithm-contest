#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
int a[N], b[N], s[N];

bool check(int x) {
    int mi = 1e9, pre = 1e9, pos = -1e9;
    for(int i = 1; i <= n; i ++) {
        if(a[i] < x) b[i] = 0;
        else b[i] = 1;
        s[i] = s[i - 1] + b[i];
        if(i - k >= 0 && mi >= 2 * s[i - k] - (i - k)) {
            mi = 2 * s[i - k] - (i - k);
            pos = i - k, pre = s[i - k];
        }

        if(s[i] - pre - 1 >= (i - pos) / 2) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    int l = 1, r = n;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << r << "\n";
    return 0;
}