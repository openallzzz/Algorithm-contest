#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n;
int h[N][N];
bool st[N][N];

void bfs(int sx, int sy, bool& has_upper, bool& has_lower) {
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;

    while(q.size()) {
        PII t = q.front(); q.pop();

        for(int i = t.x - 1; i <= t.x + 1; i ++)
            for(int j = t.y - 1; j <= t.y + 1; j ++) { // 8联通写法
                if(i == t.x && j == t.y) continue;
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                if(h[i][j] != h[t.x][t.y]) {
                    if(h[i][j] > h[t.x][t.y]) has_upper = true;
                    else has_lower = true;
                } else if(!st[i][j]) {
                    st[i][j] = true;
                    q.push({i, j});
                }
            }
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            scanf("%d", &h[i][j]);

    int top = 0, dep = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            if(!st[i][j]) {
                bool has_upper = false, has_lower = false;
                bfs(i, j, has_upper, has_lower);
                if(!has_upper) top ++ ;
                if(!has_lower) dep ++ ;
            }

    printf("%d %d\n", top, dep);
    return 0;
}