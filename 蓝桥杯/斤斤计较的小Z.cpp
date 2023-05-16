#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int N = 1000010, P = 131;

int n, m;
char s[N], t[N];
ULL s1[N], s2[N], p[N];

ULL get(ULL s[], int l, int r) {
    return s[r] - s[l - 1] * p[r - l + 1];
}

int main() {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1); m = strlen(t + 1);

    p[0] = 1;
    for(int i = 1; i <= max(n, m); i ++) p[i] = p[i - 1] * P;

    for(int i = 1; i <= n; i ++) {
        s1[i] = s1[i - 1] * P + s[i];
    }

    for(int i = 1; i <= m; i ++) {
        s2[i] = s2[i - 1] * P + t[i];
    }

    int res = 0;
    for(int i = 1; i + n - 1 <= m; i ++) {
        if(get(s2, i, i + n - 1) == get(s1, 1, n)) res ++ ;
    }

    printf("%d\n", res);
    return 0;
}