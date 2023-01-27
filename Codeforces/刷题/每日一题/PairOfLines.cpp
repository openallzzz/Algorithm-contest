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

const int N = 1e5 + 10;

LL n, x1, y1, x2, y2, x3, y3, x4, y4, x, y;
PLL ps[N];
bool st[N], i3, i4;

bool slove(int a, int b)
{
    i3 = i4 = true;
    st[1] = st[2] = st[3] = false;
    st[a] = st[b] = true;
    x1 = ps[a].x, y1 = ps[a].y;
    x2 = ps[b].x, y2 = ps[b].y;

    for(int i = 1; i <= n; i ++)
    {
        x = ps[i].x, y = ps[i].y;
        if(st[i]) continue;
        
        if((y - y1) * (x2 - x1) == (y2 - y1) * (x - x1)) ;
        else if(i3) x3 = x, y3 = y, i3 = false;
        else if(i4) x4 = x, y4 = y, i4 = false;
        else if((y4 - y3) * (x - x3) == (y - y3) * (x4 - x3)) ;
        else return false;
    }

    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> ps[i].x >> ps[i].y;

    if(n <= 3) puts("YES");
    else {
        if(slove(1, 2) || slove(2, 3) || slove(1, 3)) puts("YES");
        else puts("NO");
    }

    return 0;
}