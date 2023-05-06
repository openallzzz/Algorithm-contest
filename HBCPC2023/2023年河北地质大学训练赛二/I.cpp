#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 35;

int n, m, T;
int g[N][N];
LL f[N][N];

void solve() {
    cin >> n >> m;
    cin >> T;
    while(T --) {
        int x, y;
        cin >> x >> y;
        x ++ , y ++ ;
        g[x][y] = 1;
    }
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            if(g[i][j] == 1) continue;
            if(i == 1 && j == 1) f[i][j] = 1;
            if(j > 1) f[i][j] += f[i][j - 1];
            if(i > 1) f[i][j] += f[i - 1][j];
        }

    cout << f[n][m] << "\n";
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