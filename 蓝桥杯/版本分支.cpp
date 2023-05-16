#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][20]; // fa[u][j] : 结点u的2^j祖先

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void init(int root) {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;

    queue<int> q;
    q.push(root);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if(depth[j] > depth[u] + 1) {
                depth[j] = depth[u] + 1;
                q.push(j);
                // 更新fa数组
                for(int k = 0; k < 20; k ++) {
                    if(!k) fa[j][k] = u;
                    else fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    for(int k = 19; k >= 0; k --) { // 从大到小枚举
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

    return fa[a][0];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    init(1);

    while(m --) {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);
        if(p == x) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}