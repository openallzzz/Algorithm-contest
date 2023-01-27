#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

// Want to attack openallzzz? Just think about it.

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, m;
int a[N];
LL suf[N];

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i ++) suf[i] = suf[i - 1] + 0ll + a[i];

        LL res = 0;
        for(int i = 1; i < n; i ++) {
            res = max(res, gcd(suf[i], suf[n] - suf[i]));
        }

        printf("%lld\n", res);
    }
    return 0;
}