#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 20;

int n, k;
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
    scanf("%d", &n);
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

    int ans = 0, last = -1;
    for(int i = 0; i < n; i ++) {
        int l = last + 1, r = i;
        while(l < r) {
            int mid = l + r >> 1;
            if(query(mid, i) < (i - mid + 1)) l = mid + 1; // 使得gcd值变大
            else r = mid;
        }

        if(query(r, i) == (i - r + 1)) {
            ans ++ , last = i;
        }
    }

    cout << ans << "\n";
    return 0;
}