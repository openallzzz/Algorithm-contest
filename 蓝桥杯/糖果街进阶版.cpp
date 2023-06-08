#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, k;
int f[N][2];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) {
        int w;
        scanf("%d", &w);
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[max(0, i - k)][0] + w;
    }

    printf("%d\n", max(f[n][0], f[n][1]));
    return 0;
}