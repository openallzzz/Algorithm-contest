#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[N];
LL f[N][2];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    f[1][0] = 0, f[1][1] = -a[1];
    for(int i = 2; i <= n; i ++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + 0ll + a[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);
    }

    cout << f[n][0] << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}