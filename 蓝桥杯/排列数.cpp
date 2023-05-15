#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, MOD = 123456;

int n, k;
int f[N][N];

int main() {
    cin >> n >> k;

    f[1][0] = 1;
    for(int i = 2; i <= n; i ++ ) {
        f[i][0] = 2;
        for(int j = 0; j <= i - 2; j ++) { // i个点，最多i - 2个折点
            f[i + 1][j + 2] = (f[i + 1][j + 2] + f[i][j] * ((i - 1) - (j + 1))) % MOD;
            f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * 2) % MOD;
            f[i + 1][j] = (f[i + 1][j] + f[i][j] * (i + 1 - 2 - (i - j - 2))) % MOD; 
        }
    }

    cout << f[n][k - 1] << "\n";
    return 0;
}