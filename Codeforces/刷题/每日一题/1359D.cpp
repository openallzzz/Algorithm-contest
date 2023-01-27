#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    // start coding!

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    int res = 0; // 选任意一个数作为[l, r](l == r)即是初始值
    for(int mx = 1; mx <= 30; mx ++) {  // 枚举最大值即可，小于零的最大值，sum(seg) - max(seg) = 0恒成立
        int idx = 1;
        while(true) {
            while(idx <= n && a[idx] > mx) idx ++ ;  // 大于最大值的数不参与字段和的求解
            if(idx >= n + 1) break;

            int sum = a[idx], mxS = a[idx], flag = 0;
            for(idx ++ ; idx <= n && a[idx] <= mx; idx ++) {
                sum = max(sum + a[idx], a[idx]); // 以a[idx - 1]结尾的最大的字段和
                mxS = max(mxS, sum);
                if(a[idx] == mx) flag ++ ;
            }

            res = max(res, mxS - mx);
        }
    }

    cout << res << "\n";
    return 0;
}