#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 50010, M = 200010, INF = 0x3f3f3f3f;

int n, m, res;
int start[7], dist[7][N];
int h[N], e[M], ne[M], w[M], idx;
bool st[N], vis[6];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

void dijkstra(int sr, int dist[]) {
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> que;

    dist[sr] = 0;
    que.push({0, sr});
    while(que.size()) {
        auto tt = que.top(); que.pop();

        if(st[tt.y]) continue;
        st[tt.y] = true;

        for(int i = h[tt.y]; ~i; i = ne[i]) {
            int j = e[i];
            if(dist[j] > tt.x + w[i]) {
                    dist[j] = tt.x + w[i];
                    que.push({dist[j], j});
            }
        }
    }
}

void dfs(int u, int cost, int p) {
    if(u == 6) {
        res = min(res, cost);
    }

    if(cost > res) return ;

    for(int i = 2; i <= 6; i ++) {
        if(!vis[i]) {
            vis[i] = true;
            dfs(u + 1, cost + dist[p][start[i]], i);
            vis[i] = false;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    start[1] = 1;
    for(int i = 2; i <= 6; i ++) scanf("%d", &start[i]);


    memset(h, -1, sizeof h);
    while(m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    memset(dist, 0x3f, sizeof dist);
    for(int i = 1; i <= 6; i ++) dijkstra(start[i], dist[i]);

    res = INF;
    dfs(1, 0, 1);

    printf("%d\n", res);
    return 0;
}