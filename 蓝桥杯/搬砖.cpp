#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 20010;

int n;
PII p[N];
int f[N][M];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i].x >> p[i].y;

    sort(p + 1, p + n + 1, [](PII& a, PII b) {
        return a.x + a.y < b.x + b.y;
    });

    for(int i = 1; i <= n; i ++) {
        int w = p[i].x, v = p[i].y;
        for(int j = 0; j <= 20000; j ++) { // 枚举总重量
            f[i][j] = f[i - 1][j];
            if(j - w <= v && j - w >= 0) {
                f[i][j] = max(f[i][j], f[i - 1][j - w] + v);
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= 20000; i ++) res = max(res, f[n][i]);
    cout << res << "\n";
    return 0;
}