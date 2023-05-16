#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 25;

int n;
bool st[N][N];
vector<int> path;
int row[N], col[N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y) {
    if(x == n - 1 && y == n -1) {
        for(int i = 0; i < n; i ++) {
            if(row[i] || col[i])
                return false;
        }

        return true;
    }

    for(int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < n && b >= 0 && b < n && !st[a][b] && row[a] >= 1 && col[b] >= 1) {
            st[a][b] = true;
            path.push_back(a * n + b);
            row[a] -- , col[b] -- ;
            if(dfs(a, b)) return true;
            row[a] ++ , col[b] ++ ;
            st[a][b] = false;
            path.pop_back();
        }
    }

    return false;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> col[i];
    for(int i = 0; i < n; i ++) cin >> row[i];

    row[0] -- , col[0] -- ;
    path.push_back(0);
    st[0][0] = true;
    dfs(0, 0);

    for(int x : path) cout << x << " ";

    return 0;
}