#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int y = 1777, m = 4, d = 30;

void solve() {
    int cnt = 8113; // 8113
    for(int i = 0; i < cnt - 1; i ++) {
        int _d = days[m];
        if(is_leap(y) && m == 2) _d ++ ;
        d ++ ;
        if(d > _d) {
            d = 1;
            m ++ ;
            if(m > 12) y ++ , m = 1;
        }
    }

    string __y = to_string(y);
    string __m = to_string(m);
    if(__m.size() == 1) __m = '0' + __m;
    string __d = to_string(d);
    if(__d.size() == 1) __d = '0' + __d;

    cout << __y << "-" << __m << "-" << __d << "\n";
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