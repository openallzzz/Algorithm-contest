#include <bits/stdc++.h>

using namespace std;

bool cinT = true; // 多组数据

typedef long long LL;

const int N = 2e5 + 10, MOD = 1e9 + 7;

int n;
int a[N], b[N];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int res = 1;
    for(int i = 0, j = 0; i < n; i ++) {
        while(j < n && a[i] > b[j]) j ++ ;
        res = (res * 1ll * max(j - i, 0)) % MOD;
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
};