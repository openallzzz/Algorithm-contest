#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 510;

int n;
ll f[N][N]; // 减肥总量 ：当前周减去的重量

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        f[i][i] = 1;
        for(int j = 1; j < i; j ++) {
            for(int k = 0; k < j && j + k <= i; k ++) {
                f[i][j] += f[i - j][k];
            }
        }
    }

    ll ans = 0;
    for(int j = 1; j < n; j ++) ans += f[n][j];

    cout << ans << "\n";

    return 0;
}