#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;

const int N = 1010;

int n, d;
PDD p[N];
PDD segs[N];

bool cmp(PDD a, PDD b) {
    return a.y < b.y;
}

void solve() {
    cin >> n >> d;
    for(int i = 0; i < n; i ++) {
        cin >> p[i].x >> p[i].y;
        if(p[i].y < 0) p[i].y *= -1;
    }

    for(int i = 0; i < n; i ++) {
        if(p[i].y > d) {
            cout << "-1" << "\n";
            return ;
        }

        double dx = sqrt(d * d - p[i].y * p[i].y);
        segs[i] = {p[i].x - dx, p[i].x + dx};
    }

    sort(segs, segs + n, cmp);

    int res = 0;
    double last = -1e10;
    for(int i = 0; i < n; i ++) {
        if(last < segs[i].x) res ++ , last = segs[i].y;
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}