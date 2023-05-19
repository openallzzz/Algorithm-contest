#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, q;
int g[N][N];
int down[N][N];
int back_up[N][N];
int sub[N];

bool check_down() {
    memcpy(back_up, down, sizeof back_up);
    for(int k = 0; k < n; k ++)
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                back_up[i][j] = min(back_up[i][j], back_up[i][k] + back_up[k][j]);

    int sum = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            sum += back_up[i][j];
    
    return sum > q;
}

bool check_start() {
    memcpy(back_up, g, sizeof back_up);
    for(int k = 0; k < n; k ++)
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                back_up[i][j] = min(back_up[i][j], back_up[i][k] + back_up[k][j]);

    int sum = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            sum += back_up[i][j];
    
    return sum <= q;
}

bool check(int X) {
    memcpy(back_up, g, sizeof back_up);
    int base = X / n, r = X % n;
    for(int i = 0; i < n; i ++) {
        sub[i] = base + (i < r);
    }
    for(int i = 0; i < n; i ++)    
        for(int j = 0; j < n; j ++) {
            back_up[i][j] = max(back_up[i][j] - sub[i] - sub[j], down[i][j]);
        }

    for(int k = 0; k < n; k ++)
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                back_up[i][j] = min(back_up[i][j], back_up[i][k] + back_up[k][j]);

    int sum = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            sum += back_up[i][j];
    
    return sum <= q;
}

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> g[i][j];

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> down[i][j];

    if(check_down()) {
        cout << -1 << "\n";
    } else if(check_start()) {
        cout << 0 << "\n";
    } else {
        int l = 1, r = 10000000;
        while(l < r) {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << "\n";
    }

    return 0;
}