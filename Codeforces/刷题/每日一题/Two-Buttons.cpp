#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    
    int res = 0;
    while(m > n) {
        if(m % 2 == 0) m /= 2;
        else m += 1;
        res ++ ;
    }

    cout << res + n - m << '\n';
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