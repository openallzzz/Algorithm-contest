#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

void solve() {
    string s;
    cin >> s;
    for(char& c: s) {
        c = toupper(c);
    }
    cout << s << "\n";
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