#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500010, M = 1000010;

int n, k;
int a[N], cnt[M];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    int res = 0, l, r, m = 0;
    for(int i = 0, j = 0; j < n; j ++) {
        if(!cnt[a[j]]) m ++ ;
        cnt[a[j]] ++ ;
        while(m > k) {
            cnt[a[i]] -- ;
            if(cnt[a[i]] == 0) m -- ;
            i ++ ;
        }
        if(j - i + 1 > res) {
            res = j - i + 1;
            l = i, r = j;
        }
    }

    cout << l + 1 << " " << r + 1 << "\n";
    return 0;
}