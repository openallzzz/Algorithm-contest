#include <bits/stdc++.h>

using namespace std;

const int N = 105;

struct node {
    int x, y, z;
};

int l, n, m, tx, ty, tz;
char g[N][N][N];
int dist[N][N][N]; // 权值为1的最短路，不需要定义状态数组，节省空间

int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void solve() {
    
    memset(dist, -1, sizeof dist);

    queue<node> que;
    for(int z = 0; z < l; z ++) {
        for(int x = 0; x < n; x ++) {
            for(int y = 0; y < m; y ++) {
                cin >> g[x][y][z];
                if(g[x][y][z] == 'S') {
                    que.push({x, y, z});
                    dist[x][y][z] = 0;
                } else if(g[x][y][z] == 'E') {
                    tx = x, ty = y, tz = z;
                }
            }
        }
    }

    while(que.size()) {
        auto t = que.front(); que.pop();
        if(t.x == tx && t.y == ty && t.z == tz) break;
        int x = t.x, y = t.y, z = t.z;
        for(int i = 0; i < 6; i ++) {
            int a = x + dx[i], b = y + dy[i], c = z + dz[i];
            if(a >= 0 && a < n && b >= 0 && b < m && c >= 0 && c < l &&
                dist[a][b][c] == -1 && g[a][b][c] != '#') {
                dist[a][b][c] = dist[x][y][z] + 1;
                que.push({a, b, c});
            }
        }
    }

    if(dist[tx][ty][tz] != -1) {
        cout << "Escaped in "
             << dist[tx][ty][tz]
             << " minute(s)." << "\n";
    } else {
        cout << "Trapped!" << "\n";
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    while(cin >> l >> n >> m,
        l || n || m) {
        solve();
    }
    
    return 0;
}