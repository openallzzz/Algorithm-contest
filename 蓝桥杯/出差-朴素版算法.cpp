#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int g[N][N];
int dist[N], st[N], v[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < n; i ++) {
        int t = -1;
        for(int j = 1; j <= n; j ++) {
            if(!st[j] && (t == -1 || (dist[j] < dist[t]))) {
                t = j;
            }
        }

        if(t == -1) break;
        for(int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }

    return dist[n];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i];
    v[n] = 0;

    memset(g, 0x3f, sizeof g);
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c + v[b];
        g[b][a] = c + v[a];
    }

    cout << dijkstra() << "\n";
    return 0;
}