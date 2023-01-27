#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    int a, b, c, d, x, y, res;
    cin >> T;
    while(T --)
    {
        cin >> a >> b >> c >> d;
        res = a;
        x = y = a, a = 0;
        int t = 0;
        while(true) {
            int cnt = 0;
            if(b) {
                t = min(y, b);
                y -= t, x += t, b -= t;
                res += t;
                if(t > 0) cnt ++ ;
            }
            if(c) {
                t = min(x, c);
                x -= t, y += t, c -=t;
                res += t;
                if(t > 0) cnt ++ ;
            }
            if(cnt == 0) break;
        }
        t = min(x, y);

        int bb = 0, cc = 0, dd = 0;
        if(y >= b) bb = b;
        else bb = y + 1;

        if(x >= c) cc = c;
        else cc = x + 1;

        if(t >= d) dd = d;
        else dd = t + 1;

        cout << res + max({bb, cc, dd}) << endl;
    }

    return 0;
}