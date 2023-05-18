#include <bits/stdc++.h>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int get_day(int y, int m) {
    if(m == 2 && is_leap(y)) return days[m] + 1;
    return days[m];
}

bool check(int y, int m, int d) {
    int ds = 0;
    while(y) ds += y % 10, y /= 10;
    while(m) ds += m % 10, m /= 10;
    while(d) ds += d % 10, d /= 10;

    int t = sqrt(ds);
    return t * t == ds;
}

int main() {
    int res = 0;
    for(int y = 2001; y <= 2021; y ++) {
        for(int m = 1; m <= 12; m ++) {
            for(int d = 1; d <= get_day(y, m); d ++) {
                if(check(y, m, d)) res ++ ;
            }
        }
    }

    cout << res << "\n";
    return 0;
}