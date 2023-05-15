#include <bits/stdc++.h>

using namespace std;

bool cinT = true; // 多组数据

typedef long long LL;

const int N = 200 + 10;

int n;
int a[N];
    
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cout << i * 2 << " ";
    }
    cout << "\n";
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