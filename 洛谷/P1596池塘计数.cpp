#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
char g[N][N];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int x, int y) {
    g[x][y] = '.';
    queue<PII> q;
    q.push({x, y});

    while(q.size()) {
        auto u = q.front(); q.pop();
        for(int i = 0; i < 8; i ++) {
            int a = u.first + dx[i], b = u.second + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 'W') {
                g[a][b] = '.';
                q.push({a, b});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> g[i][j];

    int res = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(g[i][j] == 'W') res ++ , bfs(i, j);
    
    cout << res << "\n";
    return 0;
}