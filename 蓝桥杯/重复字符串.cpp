#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int k;
string s;
int record[N][26];

int main() {
    cin >> k >> s;

    int n = s.size();

    if(n % k != 0) {
        cout << -1 << "\n";
    } else {

        // cout << n << " " << k << " " << n / k << "\n";
        int len = n / k;
        for(int i = 0; i + len - 1 < n; i += len) { // 0 1 2 3 4
            for(int j = i; j <= i + len - 1; j ++) {
                record[j % len][s[j] - 'a'] ++ ;
            }
        }

        int res = 0;
        for(int i = 0; i < len; i ++) {
            int cnt = 0, sum = 0, mxV = 0;
            for(int j = 0; j < 26; j ++) {
                if(record[i][j]) cnt ++ ;
                sum += record[i][j];
                mxV = max(mxV, record[i][j]);
            }
            if(cnt > 1) res += sum - mxV;
        }

        cout << res << "\n";
    }

    return 0;
}