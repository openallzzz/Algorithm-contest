#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

void solve() {
    int y, m;
    cin >> y >> m;

    int res = 0;
    if(m <= 10) {
        for(int i = m; i <= 9; i ++) res += days[i];
        if(m <= 2 && is_leap(y)) res ++ ;
    } else {
        for(int i = m; i <= 12; i ++) res += days[i];
        for(int i = 1; i <= 9; i ++) res += days[i];
        if(is_leap(y + 1)) res ++ ;
    }

    cout << res + 24 << "\n";
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