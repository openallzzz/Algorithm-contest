#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 2e5 + 10;

int n, m;
int a[N];

void solve() {
    cin >> n >> m;
    int k = n + m + 1;
    for(int i = 0; i < k; i ++) cin >> a[i];
    sort(a, a + n);

    LL res = 0;
    if(!m) {
        for(int i = 0; i < k; i ++) res += a[i];
    } else {
        res = a[k - 1] - a[0];
        for(int i = 1; i < k - 1; i ++) res += abs(a[i]);
    }

    cout << res << "\n";
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