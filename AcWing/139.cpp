#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int N = 2000010, base = 131;

char str[N];
ULL hl[N], hr[N], p[N]; // 正序哈希值 逆序哈希值

ULL get(ULL h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int T = 1;

    while(scanf("%s", str + 1), strcmp(str + 1, "END")) {
        int n = strlen(str + 1);

        for(int i = n * 2; i > 0; i -= 2) {
            str[i] = str[i / 2];
            str[i - 1] = 'z' + 1;
        }

        p[0] = 1, n *= 2;
        for(int i = 1, j = n; i <= n; i ++, j --) {
            hl[i] = hl[i - 1] * base + str[i] - 'a' + 1;
            hr[i] = hr[i - 1] * base + str[j] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }

        int res = 0;
        for(int i = 1; i <= n; i ++) {
            int l = 0, r = min(i - 1, n - i);
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(get(hl, i - mid, i - 1) != get(hr, n - (i + mid) + 1, n - (i + 1) + 1)) r = mid - 1;
                else l = mid;
            }

            if(str[i - r] <= 'z') res = max(res, r + 1);
            else res = max(res, r);
        }

        printf("Case %d: %d\n", T ++ , res);

    }

    return 0;
}