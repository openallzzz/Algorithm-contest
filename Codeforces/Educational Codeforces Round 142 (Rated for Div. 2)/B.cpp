#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T --) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(!a) cout << 1 << "\n";
        else {
            int t = min(b, c);
            b -= t, c -= t;
            if(b + c > a) cout << a * 2 + t * 2 + 1 << "\n";
            else cout << a + t * 2 + b + c + min(d, a - b - c + 1) << "\n";
        }
    }
    return 0;
}