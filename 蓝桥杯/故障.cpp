#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 45, M = 25;
const long double eps = 1e-20;

typedef pair<long double, int> PDI;

int n, m, k;
long double a[N];
long double p[N][M];
bool st[N];
PDI res[N]; // 概率 - 原因编号

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        res[i].y = i;
        for(int j = 1; j <= m; j ++) {
            cin >> p[i][j];
        }
    }

    cin >> k;
    for(int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        st[x] = true;
    }

    long double sum = 0;
    for(int i = 1; i <= n; i ++) {
        long double &x = res[i].x;
        x = a[i] / 100.0;
        for(int j = 1; j <= m; j ++) {
            if(st[j]) x *= p[i][j] / 100.0;
            else x *= (100 - p[i][j]) / 100.0;
        }
        sum += x;
    }

    sort(res + 1, res + n + 1, [](PDI& a, PDI& b) {
        if(abs(a.x - b.x) < eps) return a.y < b.y;
        return a.x > b.x;
    });

    for(int i = 1; i <= n; i ++) { // long double输出 一定是L开头
        printf("%d %.2Lf\n", res[i].y, abs(sum) < eps ? 0.00 : (res[i].x * 100.0) / sum);
    }

    return 0;
}