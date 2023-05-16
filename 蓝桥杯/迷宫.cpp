#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 2010;

int n, m;
int dist[N][N];
vector<PII> e[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<PII> q;
    q.push({n, n});

    memset(dist, 0x3f, sizeof dist);
    dist[n][n] = 0;
    while(q.size()) {
        auto u = q.front(); q.pop();

        int x = u.x, y = u.y;
        for(int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 1 && a <= n && b >= 1 && b <= n) {
                if(dist[a][b] > dist[x][y] + 1) {
                    dist[a][b] = dist[x][y] + 1;
                    q.push({a, b});
                }
            }
        }

        for(auto ne : e[x][y]) {
            int a = ne.x, b = ne.y;
            if(dist[a][b] > dist[x][y] + 1) {
                dist[a][b] = dist[x][y] + 1;
                q.push({a, b});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        e[x1][y1].push_back({x2, y2});
        e[x2][y2].push_back({x1, y1});
    }

    bfs();

    double res = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            res += dist[i][j];
    
    printf("%.2lf\n", res / (n * n));
    return 0;
}