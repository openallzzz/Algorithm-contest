#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, s[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T --) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &s[i]);
        int l = 1, r = n, st = 1, ed = n, segs = 0, res = 0;
        while(l < r) {
            while(!(s[st] <= r && s[st] >= l)) st ++ ;
            while(!(s[ed] <= r && s[ed] >= l)) ed -- ;
            if(s[st] == l && s[ed] == r) segs ++ ;
            else res += 1 + segs, segs = 0;
            l ++, r -- ;
        }
        printf("%d\n", res);
    }

    return 0;
}