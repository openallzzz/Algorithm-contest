#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n, k = 0;
LL c[N], s[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    LL b = s[n] / n;
    for(int i = 1; i < n; i ++) c[k ++ ] = i * b - s[i];
    c[k ++ ] = 0;

    nth_element(c, c + k / 2, c + k);
    LL res = 0;
    for(int i = 0; i < k; i ++) res += abs(c[i] - c[k / 2]);
    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}