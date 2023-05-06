#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;
typedef pair<LL, LL> PII;

const int N = 1e5 + 10;

LL n, m;

void solve() {
    vector<PII> res;
    for(LL len = sqrt(2 * m); len >= 1; len --) {
        if((2 * m) % len == 0 && ((2 * m) / len + 1 - len) % 2 == 0) {
            LL a = ((2 * m) / len + 1 - len) / 2;
            if((a + a + len - 1) * len / 2 != m || a > n || a + len - 1 > n) continue;
            res.push_back({a, a + len - 1});
        }
    }

    sort(res.begin(), res.end());
    for(auto it : res) {
        cout << "[" << it.first << "," << it.second << "]" << "\n";
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    int T = 1;
    if(cinT) cin >> T;
    while(cin >> n >> m) {
        solve();
    }

    return 0;
}