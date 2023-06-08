#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[N];
LL f[N][2]; // 0 ：不选 --- 1 ：选

// 奇数个 和 偶数个 都是 n / 2 (下取整)

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    f[1][0] = 0, f[1][1] = a[1];
    f[2][0] = a[1], f[2][1] = a[2];

    for(int i = 3; i <= n; i ++) {
        if(i & 1) {
            f[i][1] = max({f[i - 2][1], f[i - 2][0], f[i - 3][1], f[i - 3][0]}) + a[i];
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        } else {
            f[i][1] = max(f[i - 2][1], f[i - 2][0]) + a[i];
            f[i][0] = f[i - 2][0] + a[i - 1];
        }
    }

    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}