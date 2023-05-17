#include <bits/stdc++.h>

using namespace std;

const int N = 500010, M = N + N;

int n, m, s;
int h[N], e[M], ne[M], idx;
int fa[N][20], depth[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void init(int root) {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1; // 要点1
    queue<int> q;
    q.push(root);
    while(q.size()) {
        auto u = q.front(); q.pop();
        for(int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if(depth[j] > depth[u] + 1) {
                depth[j] = depth[u] + 1;
                q.push(j);
                for(int k = 0; k < 20; k ++) {
                    if(k == 0) fa[j][k] = u;
                    else fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    for(int k = 19; k >= 0; k --) { // 越级眺 要点2
        if(depth[fa[a][k]] >= depth[b]) {
            a = fa[a][k];
        }
    }

    if(a == b) return a;
    for(int k = 19; k >= 0; k --) {
        if(fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    }

    return fa[a][0]; // 要点3
}

int main() {
    cin >> n >> m >> s;

    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    init(s);

    while(m --) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}