#include <bits/stdc++.h>

#define x first
#define y second

// Want to attack openallzzz? Just think about it.

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n;
map<int, int> cnt;

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    // start coding!

    int T;
    cin >> T;
    while(T --) {
        cin >> n;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            cnt[x] ++ ;
        }

        LL res = 0;
        auto it = cnt.begin();
        while(it != cnt.end()) {
            int x = (*it).second - cnt[(*it).first - 1];
            res += max(0, x);
            it ++ ;
        }
        cnt.clear();
        cout << res << "\n";
    }

    return 0;
}