#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 22;

int n = 21;
int g[N][N];
LL f[1 << N][N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++) {
            if(gcd(i, j) == 1) g[i][j] = 1;
        }

    f[1][1] = 1;
    for(int i = 1; i < 1 << n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i >> j & 1) {
                int last = i & (~(1 << j));
                for(int k = 1; k <= n; k ++) {
                    if(g[j + 1][k] == 0) continue;
                    f[i][j + 1] += f[last][k];
                }
            }
        }
    }

    LL res = 0;
    for(int i = 1; i <= n; i ++) res += f[(1 << n) - 1][i];
    cout << res << "\n";
    cout << 881012367360 << "\n";
    return 0;
}