#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    LL ans = 0, l = 0, r = 0, t = 0;
    while(l < n) {
        while(r < n && ((t ^ a[r]) == (t + a[r]))) t ^= a[r ++ ];
        ans += r - l;
        t ^= a[l ++ ];
    }

    printf("%lld\n", ans);
    return 0;
}