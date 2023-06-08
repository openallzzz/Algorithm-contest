#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 20;

LL f[N][5];
int a[N], len;

LL dp(int pos, int sum, bool limit) {
    if(!pos) return 1;
    if(!limit && f[pos][sum] != -1) return f[pos][sum];

    int ans = 0, up = limit ? a[pos] : 9;
    for(int d = 0; d <= up; d ++ ) {
        if(!d) ans += dp(pos - 1, sum, limit && d == up);
        else if(sum < 3) ans += dp(pos - 1, sum + 1, limit && d == up);
    }

    if(!limit) f[pos][sum] = ans;
    return ans;
}

LL get(LL x) {
    memset(f, -1, sizeof f);
    len = 0;
    while(x) a[++ len] = x % 10, x /= 10;
    return dp(len, 0, true); // 从高位的开始枚举
}

int main() {
    int T;
    scanf("%d", &T);

    LL l, r;
    while(T --) {
        scanf("%lld%lld", &l, &r);

        printf("%lld\n", get(r) - get(l - 1));
    }

    return 0;
}