#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 55;

int n, m;
int g[N][N];
bool st[N][N];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int sx, int sy) {
    st[sx][sy] = true;
    queue<PII> q;
    q.push({sx, sy});

    int ret = 1;
    while(q.size()) {
        auto u = q.front(); q.pop();

        // 0 - 2  1 - 3  2 - 0 
        int x = u.x, y = u.y;
        for(int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && !st[a][b]) {
                if((g[x][y] >> i & 1) == 0 && (g[a][b] >> (i ^ 2) & 1) == 0) {
                    q.push({a, b});
                    st[a][b] = true;
                    ret ++ ;
                }
            }
        }
    }   

    return ret;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> g[i][j];

    int ans = 0, mxV = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(!st[i][j]) {
                ans ++ ;
                mxV = max(mxV, bfs(i, j));
            }

    cout << ans << "\n" << mxV << "\n";
    return 0;
}