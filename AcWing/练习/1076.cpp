#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 10;

int n;
int g[N][N];
int dist[N][N];
PII pre[N][N];

void bfs(int sx, int sy, int tx, int ty) {

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;
    queue<PII> q;
    q.push({sx, sy});

    while(q.size()) {
        PII t = q.front(); q.pop();

        for(int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < n && g[a][b] != 1 && dist[a][b] > dist[t.x][t.y] + 1) {
                pre[a][b] = {t.x, t.y};
                dist[a][b] = dist[t.x][t.y] + 1;
                q.push({a, b});
            }
        }
    }

    vector<PII> ans;
    while(true) {
        ans.push_back({tx, ty});
        if(tx == sx && ty == sy) break;
        PII t = pre[tx][ty];
        tx = t.x, ty = t.y;
    }

    reverse(ans.begin(), ans.end());
    for(PII t : ans) {
        cout << "(" << t.x << ", " << t.y << ")" << "\n";
    }
}

int main() {
    n = 5;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            scanf("%d", &g[i][j]);

    bfs(0, 0, n - 1, n - 1);
    return 0;
}