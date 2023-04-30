#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 64;

LL n;
int k;
LL f[N][N];
int a[N];

LL dfs(int pos, int cnt, int limit) {
    if(!pos) return cnt == k;
    if(!limit && f[pos][cnt] != -1) return f[pos][cnt];

    int up = limit ? a[pos] : 1;

    LL res = 0;
    for(int i = 0; i <= up; i ++) {
        res += dfs(pos - 1, cnt + i, limit && i == a[pos]);
    }

    if(!limit) f[pos][cnt] = res;
    return res;
}

void solve() {
    cin >> n >> k;
    int idx = 0;
    memset(f, -1, sizeof f);
    while(n) {
        a[ ++ idx] = n % 2;
        n /= 2;
    }
    cout << dfs(idx, 0, 1) << "\n";
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