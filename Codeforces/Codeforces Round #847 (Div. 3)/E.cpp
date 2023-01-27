#include <bits/stdc++.h>

#define x first
#define y second

// Want to attack openallzzz? Just think about it.

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void slove() {
    LL x;
    cin >> x;
    if(x & 1) cout << "-1" << "\n";
    else {
        LL a = 0, b = 0, d = 0, flag = 0;
        while(x) {
            int u = x % 2;
            if(u == 1) {
                if(!flag) {
                    cout << "-1" << "\n";
                    return ;
                }
                a |= 1 << d, flag = 0;
                a |= 1 << (d - 1), b |= 1 << (d - 1);
            } else flag = 1;
            d ++, x /= 2;
        }

        cout << a << ' ' << b << "\n";
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    // start coding!

    int T = 1;
    cin >> T;
    while(T --) {
        slove();
    }

    // end coding!
    return 0;
}