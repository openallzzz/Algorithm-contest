#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 160;

int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i ++) cin >> g[i];

    int sx = 0, sy = 0, tx = 0, ty = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == 'K') sx = i, sy = j;
            if(g[i][j] == 'H') tx = i, ty = j;
        }
    
    queue<PII> q;
    q.push({sx, sy});

    memset(dist, 0x3f, sizeof dist);
    st[sx][sy] = true;
    dist[sx][sy] = 0;

    while(q.size()) {
        PII u = q.front(); q.pop();

        for(int i = 0; i < 8; i ++) {
            int a = u.x + dx[i], b = u.y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m 
                && dist[a][b] > dist[u.x][u.y] + 1
                && !st[a][b] && g[a][b] != '*') {
                    st[a][b] = true;
                    dist[a][b] = dist[u.x][u.y] + 1;
                    q.push({a, b});
                }
        }
    }

    cout << dist[tx][ty] << "\n";
    return 0;
}