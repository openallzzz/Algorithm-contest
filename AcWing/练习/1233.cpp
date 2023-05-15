#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, cnt;
char g[N][N];
bool st[N][N];
PII ps[N * N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    st[x][y] = true;
    ps[cnt ++ ] = {x, y};

    for(int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < n
            && g[a][b] == '#' && !st[a][b]) {
                dfs(a, b);
            }
    }
}

bool check() {
    for(int i = 0, s = 0; i < cnt; i ++) {
        for(int k = 0; k < 4; k ++) {
            int a = ps[i].x + dx[k], b = ps[i].y + dy[k];
            if(a >= 0 && a < n && b >= 0 && b < n && g[a][b] == '#') s ++ ;
        }
        if(s == 4) return false;
        s = 0;
    }
    return true;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> g[i];

    int res = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(g[i][j] == '#' && !st[i][j]) {
                dfs(i, j);
                if(check()) res ++ ;
                cnt = 0;
            }
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);
    
    solve();
    return 0;
}