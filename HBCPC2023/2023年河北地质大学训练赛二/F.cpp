#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

LL n, res;
int h[N], e[N + N], ne[N + N], w[N + N], idx;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

LL dfs(int u, int fa) {
    LL d1 = 0, d2 = 0;
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == fa) continue;
        LL d = dfs(j, u) + 0ll + w[i];
        if(d >= d1) d2 = d1, d1 = d;
        else if(d > d2) d2 = d;
    }
    res = max(res, d1 + d2);
    return d1;
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
        add(b, a, w);
    }

    res = 0;
    dfs(1, 0);

    cout << (res * 10 + (res + 1) * res / 2) << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}