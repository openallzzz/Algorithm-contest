#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

const int N = 500010;

int n;
int a[N];

void solve() {
    long double s;
    cin >> n >> s;
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    sort(a, a + n);
    long double res = 0, avg = s / n;
    for(int i = 0; i < n; i ++) {
        long double cur = s / (n - i); // 当前的平均值
        if(a[i] < cur) cur = a[i]; // 付不起的情况下，全付即可
        res += (cur - avg) * (cur - avg);
        s -= cur;
    }

    printf("%.4llf", sqrt(res / n)); // llf是long double
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