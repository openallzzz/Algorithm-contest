#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int a[N];
vector<int> mp[25];

void dfs(int u, int dep) {
    if(u > n) return ;
    mp[dep].push_back(a[u]);
    dfs(u << 1, dep + 1);
    dfs(u << 1 | 1, dep + 1);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    dfs(1, 1);

    int res = 1;
    LL s = 0, sum = 0;
    for(int i = 1; i <= 20; i ++) {
        for(int& node : mp[i]) s += node;
        if(s > sum) res = i, sum = s;
        s = 0;
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}