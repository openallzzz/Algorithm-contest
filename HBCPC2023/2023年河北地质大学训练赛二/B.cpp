#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

int n, m;

void solve() {
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
    }

    if(m >= n - 1) cout << m - n + 1 << "\n";
    else cout << 0 << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    int T = 1;
    if(cinT) cin >> T;
    while(cin >> n >> m) {
        if(!n && !m) break;
        solve();
    }

    return 0;
}