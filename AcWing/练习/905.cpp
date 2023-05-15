#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
struct seg {
    int l, r;
    bool operator<(const seg& s) const {
        return r < s.r;
    }
}p[N];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> p[i].l >> p[i].r;

    sort(p, p + n);
    int res = 0, last = -(1e9 + 7);
    for(int i = 0; i < n; i ++) {
        if(last < p[i].l) res ++ , last = p[i].r;
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}