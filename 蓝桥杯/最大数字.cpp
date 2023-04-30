#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n, res = 0;
int a, b;
string s;

void dfs(int u, LL v) {
    if(u == (int)s.size()) {
        res = max(res, v);
        return ;
    }

    LL x = s[u] - '0';
    LL t = min((LL)a, 9 - x);
    a -= t;
    dfs(u + 1, v * 10ll + x + t);
    a += t;

    if(b >= x + 1) {
        b -= x + 1;
        dfs(u + 1, v * 10ll + 9ll);
        b += x + 1;
    }
}

int main() {
    cin >> n >> a >> b;
    s = to_string(n);

    dfs(0, 0ll);

    cout << res << "\n";
    return 0;
}