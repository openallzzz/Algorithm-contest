#include <iostream>
#include <cstring>
#include <algorithm>

// Want to attack openallzzz? Just think about it.

using namespace std;

const int N = 5e4 + 10, M = 15;

int n, m;
int seqs[N][M], tmp[M];
int son[N * 10][M], idx;

void insert(int s[])
{
    int p = 0;
    for(int i = 1; i <= m; i ++)
    {
        int u = s[i];
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int get_ans(int s[])
{
    int p = 0, res = m;
    for(int i = 1; i <= m; i ++)
    {
        int u = s[i];
        if(!son[p][u]) res = i - 1, i = m + 1;
        p = son[p][u];
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                scanf("%d", &seqs[i][j]);
                tmp[seqs[i][j]] = j;  // 逆排列
            }
         
            insert(tmp);
        }

        for(int i = 1; i <= n; i ++) printf("%d ", get_ans(seqs[i]));
        puts("");

        for(int i = 0; i <= idx; i ++) memset(son[i], 0, sizeof son[i]);
        idx = 0;
    }

    return 0;
}