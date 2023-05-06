#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 15;

int n, m, res = 1000, sum = 0;
int g[N][N];
bool vis[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int v, int cnt)
{
    vis[x][y] = true;
    if (v > sum)
        return;
    if (v == sum)
    {
        res = min(res, cnt);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && !vis[a][b])
        {
            dfs(a, b, v + g[a][b], cnt + 1);
            vis[a][b] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            sum += g[i][j];
        }

    if (sum % 2 == 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        sum /= 2;
        dfs(0, 0, g[0][0], 1);
        cout << res << "\n";
    }

    return 0;
}