#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int s = 0; s <= 6; s ++) // 30 * 1 / 60
        for(int f = 0; f < 60; f ++) // 6
            for(int m = 0; m < 60; m ++) { // 6
                if(s == 0 && f == 0 && m == 0) continue;
                double dm = m * 6;
                double df = f * 6 + m / 10.0;
                double ds = s * 30 + f / 2.0 + m / 120.0;
                double A = fabs(ds - df), B = fabs(df - dm);
                A = min(A, 360 - A), B = min(B, 360 - B);
                if(fabs(A - 2 * B) < 1e-4) {
                    cout << s << ' ' << f << ' ' << m << endl;
                    return 0;
                }
            }
    return 0;
}