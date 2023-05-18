#include <bits/stdc++.h>
using namespace std;
int main() {
    // vector<long long> a(20000000);
    // a[1] = 1, a[2] = 1;

    // for(int i = 3; i < 20000000; i ++) a[i] = (a[i - 1] + a[i - 2]) % (int)1e9;

    // vector<int> pre(20000001);
    // for(int i = 1; i <= 20000000; i ++) {
    //     pre[i] = pre[i - 1] + (a[i] % 10 == 7);
    // }

    // cout << pre[600] << "\n";
    // cout << pre[1200] << "\n";

    long long cnt = 202202011200;
    long long sz = cnt / 600;

    unsigned long long res = 80 * sz;

    cout << res << "\n";

    return 0;
}

// 27 26 27