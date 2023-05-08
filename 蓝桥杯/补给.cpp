#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 25;
const double INF = 1e12;

int n, d;
PII p[N];
double dist[N][N];
double f[1 << 20][20]; // f[i][j] : i为已经走过的点的集合，j为最后一个到达的点

double get(PII a, PII b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void floyd() {
    for(int k = 0; k < n; k ++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i ++) scanf("%d%d", &p[i].x, &p[i].y);

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            double d_ = get(p[i], p[j]);
            if(d_ <= d) dist[i][j] = d_;
            else dist[i][j] = INF;
        }
    }

    floyd();

    for(int i = 0; i < 1 << n; i ++)
        for(int j = 0; j < n; j ++)
            f[i][j] = INF;

    f[1][0] = 0;
    for(int i = 0; i < (1 << n); i ++) {
        for(int j = 0; j < n; j ++) {
            if(i >> j & 1) {
                for(int k = 0; k < n; k ++) {
                    if(k != j && i >> k & 1) {
                        f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    double res = INF;
    for(int i = 0; i < n; i ++) {
        res = min(res, f[(1 << n) - 1][i] + dist[i][0]);
    }

    printf("%.2lf\n", res);
    return 0;
}