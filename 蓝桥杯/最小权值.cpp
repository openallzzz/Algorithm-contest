#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5010;

int n = 2021;
vector<LL> f(N, 1e18);

int main() {
    f[0] = 0;
    for(int i = 1; i <= n; i ++) { // 总结点
        for(int l = 0; l < i; l ++) { // 枚举左子树的数量
            int r = i - 1 - l; // 右子树的数量
            f[i] = min(f[i], 1 + 0ll + 2 * f[l] + 3 * f[r] + l * l * r);
        }
    }

    cout << f[n] << "\n";
    return 0;
}