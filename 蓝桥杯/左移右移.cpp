#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 200010;

int n, m;
PII a[N];

bool cmp(PII& a, PII& b) {
    return a.y < b.y;
}

int main() {
    scanf("%d%d", &n, &m);

    int l = 0, r = N + 1;
    for(int i = 1; i <= n; i ++) {
        a[i].x = a[i].y = i;
    }

    int x;
    char op[2];
    while(m --) {
        scanf("%s %d", op, &x);
        if(op[0] == 'L') {
            a[x].y = l -- ;
        } else {
            a[x].y = r ++ ;
        }
    }

    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i ++) {
        printf("%d ", a[i].x);
    }

    return 0;
}