#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

int n;
map<int, int> cnt;

void solve() {
    cin >> n;
    while(n --) {
        int x;
        cin >> x;
        cnt[x] ++ ;
    }

    int res = 0, count = 0;
    for(auto it : cnt) {
        if(it.second > count) {
            res = it.first;
            count = it.second;
        }
    }

    cout << res << "\n" << count << "\n";
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