#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, k;
char g[N][N];
bool st[N][N][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct node {
    int x, y, r, d;
};

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) cin >> g[i];

    queue<node> q;
    st[0][0][0] = 1;
    q.push({0, 0, 0, 0});

    int res = -1;
    while(q.size()) {
        node u = q.front(); q.pop();
        int x = u.x, y = u.y, r = u.r, d = u.d;

        if(x == n - 1 && y == n - 1) {
            res = d;
            break;
        }

        for(int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < n) {
                if(g[a][b] == '#') continue;

                if(g[a][b] == '%' && !st[a][b][k]) {
                    st[a][b][k] = true;
                    q.push({a, b, k, d + 1});
                } else {
                    if(r > 0 && !st[a][b][r - 1]) { // 无敌且可访问
                        st[a][b][r - 1] = true;
                        q.push({a, b, r - 1, d + 1});
                    } else if(g[a][b] == '.' && !r && !st[a][b][0]) {
                        st[a][b][0] = true;
                        q.push({a, b, 0, d + 1});
                    }
                }
            }
        }
    }

    cout << res << "\n";
    return 0;
}