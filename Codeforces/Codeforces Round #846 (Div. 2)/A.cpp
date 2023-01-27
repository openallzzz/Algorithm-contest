#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define x first
#define y second

// Want to attack openallzzz? Just think about it.

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 3e2 + 10;

int n;
int a[N];
vector<int> even, odd;

int main()
{
    int T;
    cin >> T;
    while(T --) {
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i], cnt += a[i] & 1;
            if(a[i] & 1) odd.push_back(i);
            else even.push_back(i);
        }
        if((cnt >= 1 && (n - cnt) >= 2) || cnt >= 3) {
            puts("YES");
            if(cnt >= 1 && n - cnt >= 2) {
                cout << odd[0] << ' ' << even[0] << ' ' << even[1] << "\n";
            } else if(cnt >= 3) {
                cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << "\n";
            }
        }
        else {
            puts("NO");
        }
        even.resize(0);
        odd.resize(0);
    }

    return 0;
}