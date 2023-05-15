#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n;
int a[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    int res = 0;
    for(int i = 1; i <= n; i ++) {
        while(a[i] != i) {
            res ++ ;
            swap(a[i], a[a[i]]); // 将a[i]放在a[i]位置上
        }
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}