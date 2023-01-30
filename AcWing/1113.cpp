#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 25;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m;
char g[N][N];
bool st[N][N];

void solve() {

    memset(st, 0, sizeof st);

    for(int i = 0; i < n; i ++) cin >> g[i];

    int sx, sy;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(g[i][j] == '@') sx = i, sy = j;

    int res = 1;
    queue<PII> que;
    que.push({sx, sy});
    st[sx][sy] = true;

    while(que.size()) {
        auto t = que.front(); que.pop();
        for(int i = 0; i < 4; i ++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#' || st[x][y]) continue;
            res ++, st[x][y] = true;
            que.push({x, y});
        }
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    while(cin >> m >> n) {
        if(!m && !n) break;
        solve();
    }

    return 0;
}