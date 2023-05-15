#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10, MOD = 1000000009;

int n, k;
int a[N];

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) cin >> a[i];

    sort(a, a + n);

    int res = 1, l = 0, r = n - 1, sign = 1;
    if(k % 2) {
        res = a[r -- ], k -- ;
        if(res < 0) sign = -1;
    }

    while(k) {
        LL x = (LL)a[l] * a[l + 1], y = (LL)a[r - 1] * a[r];
        if(x * sign > y * sign) {
            res = x % MOD * res % MOD;
            l += 2;
        } else {
            res = y % MOD * res % MOD;
            r -= 2;
        }
        k -= 2;
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    int T = 1;
    if(cinT) cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}