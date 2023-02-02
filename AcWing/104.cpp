#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int p[N];

int quick_select(int l, int r, int k) {
    if(l >= r) return p[r];

    int x = p[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do i ++ ; while(p[i] < x);
        do j -- ; while(p[j] > x);
        if(i < j) swap(p[i], p[j]);
    }

    int sl = j - l + 1;
    if(sl >= k) return quick_select(l, j, k);
    return quick_select(j + 1, r, k - sl);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i];

    int mid = quick_select(1, n, n / 2 + 1);
    int res = 0;

    for(int i = 1; i <= n; i ++) res += abs(p[i] - mid);
    cout << res << endl;
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}