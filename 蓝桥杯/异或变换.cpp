#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e4 + 10;

int n;
LL t;
int a[N];

void solve() {
    string s;
    cin >> n >> t;
    cin >> s;
    // 将字符串数组转化为01数组
    for(int i = 1; i <= n; i ++) a[i] = s[i - 1] - '0';

    LL C = 1;
    while(C < n) {
        C <<= 1;
    }

    t %= C;
    while(t --) {
        for(int i = n; i >= 2; i --) a[i] ^= a[i - 1];
    }

    for(int i = 1; i <= n; i ++) cout << a[i];
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    int T = 1;
    if(cinT) cin >> T;
    while(T --) {
        solve();
    }

    return 0;
}