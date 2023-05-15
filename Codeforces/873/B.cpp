#include <bits/stdc++.h>

using namespace std;

bool cinT = true; // 多组数据

typedef long long LL;

const int N = 2e5 + 10;

int n;
int a[N];
int pos[N];

// bool check(int X) {
//     memset(st, false, sizeof st);
//     unordered_map<int, int> hash;
//     for(int i = 1; i <= n; i ++) {
//         if(st[i]) continue;
//         for(int j = i; j <= n; j += X) {
//             if(st[j]) continue;
//             st[j] = true;
//             hash[j] ++ ;
//             if(hash[j] == 0) hash.erase(j);
//             hash[a[j]] --;
//             if(hash[a[j]] == 0) hash.erase(a[j]);
//         }

//         if(hash.size() != 0) return false;
//         hash.clear();
//     }

//     return true;
// }

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) pos[a[i]] = i;

    int res = 0;
    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        if(x == pos[x]) continue;
        res = gcd(res, abs(pos[x] - x));
    }

    cout << res << "\n";

    // int l = 1, r = n - 1;
    // while(l < r) {
    //     int mid = l + r + 1 >> 1;
    //     if(check(mid)) l = mid;
    //     else r = mid - 1;
    // }
    // cout << r << "\n";
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