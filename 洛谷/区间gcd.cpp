#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1010, M = 20;

int n, m, k;
int a[N];
int f[N][M]; // ST表的本质是DP

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int query(int l, int r)
{
    int len = r - l + 1;
    int k = log(len) / log(2);
    int ll = f[l][k], rr = f[r - (1 << k) + 1][k];
    return gcd(ll, rr);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    // 初始化ST表
    k = log(n) / log(2);
    for(int j = 0; j <= k; j ++) // 枚举区间长度
        for(int i = 0; i + (1 << j) - 1 < n; i ++) // 枚举左端点
        {   
            if(!j) f[i][j] = a[i]; // 模板的可转变性
            else
            {
                int l = f[i][j - 1], r = f[i + (1 << j - 1)][j - 1];
                f[i][j] = gcd(l, r);
            }
        }

    // 处理查询
    int l, r;
    while (m --)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l - 1, r - 1));
    }

    return 0;
}