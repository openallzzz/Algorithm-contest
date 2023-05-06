#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 20 + 10, M = 100010;

int n, m;
int v[N];
int f[N][M];

void solve() {
    cin >> m >> n;
    for(int i = 1; i <= n; i ++) cin >> v[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i]);
        }
    }

    cout << m - f[n][m] << "\n";
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