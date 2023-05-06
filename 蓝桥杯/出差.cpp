#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 20010;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int v[N], dist[N], st[N];

void add(int a, int b, int c) {
    c += v[b];
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while(heap.size()) {
        auto t = heap.top(); heap.pop();

        int node = t.second;

        if(st[node]) continue;
        st[node] = true;

        for(int i = h[node]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[node] + w[i]) {
                dist[j] = dist[node] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    return dist[n];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i];
    v[n] = 0;

    memset(h, -1, sizeof h);
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    if(n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    cout << dijkstra() << "\n";
    return 0;
}