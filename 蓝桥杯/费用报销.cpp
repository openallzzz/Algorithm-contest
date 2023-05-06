#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 5010;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(int m, int d) {
    int res = 0;
    for(int i = 1; i < m; i ++) res += days[i];
    return res + d;
}

int n, m, k;
struct e { // 票据
    int m, d, v;
    bool operator<(e w) const {
        return get(m, d) < get(w.m, w.d);
    }
}p[N];
bool f[N][M]; // f[i][j]: 从前i个票据中选取若干个是否存在能凑成价值为j的方案

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) cin >> p[i].m >> p[i].d >> p[i].v;

    sort(p + 1, p + n + 1);

    f[0][0] = true;
    for(int i = 1; i <= n; i ++) {
        int last = i - 1;
        while(last > 0 && get(p[i].m, p[i].d) - get(p[last].m, p[last].d) < k) last -- ;
        for(int j = 0; j <= m; j ++) {
            f[i][j] = f[i - 1][j];
            if(j >= p[i].v) f[i][j] |= f[last][j - p[i].v];
        }
    }

    int res = 0;
    for(int i = m; i >= 0; i --) {
        if(f[n][i]) {
            res = i;
            break;
        }
    }

    cout << res << "\n";
    return 0;
}