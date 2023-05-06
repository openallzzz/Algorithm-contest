#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1000 + 10;

int n;
int g[N][N];

void solve() {
    cin >> n;
    int v = 0;
    int x = 0, y = 0, len = n;
    while(len > 0) {
        for(int j = y; j < y + len; j ++) g[x][j] = v;
        for(int i = x; i < x + len; i ++) g[i][y + len - 1] = v;
        for(int j = y; j < y + len; j ++) g[x + len - 1][j] = v;
        for(int i = x; i < x + len; i ++) g[i][y] = v;
        x ++ , y ++ , len -= 2 , v ++ ;
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++)
            cout << g[i][j];
        cout << "\n";
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    int T = 1;
    if(cinT) cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}