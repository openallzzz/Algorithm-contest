#include <bits/stdc++.h>

using namespace std;

bool cinT = true; // 多组数据

typedef long long LL;

const int N = 3e5 + 10;

int n;
LL a[N], s[N];
bool st[N];

void solve() {
	s[0] = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];

	LL s0 = s[0], sn = s[n];
	if(s0 > sn) swap(s0, sn);
	sort(s, s + n + 1);

	for(int i = 0; i <= n; i ++)
		if(s[i] == s0) {
		    s0 = i;
		    break;
		}

	for(int i = n; i >= 0; i --)
		if(s[i] == sn) {
		    sn = i;
		    break;
		}

	memset(st, 0, sizeof st);
	int l = 0, r = n;
	for(int i = s0; i >= 0; i -= 2) a[l ++ ] = s[i], st[i] = true;
	for(int i = sn; i <= n; i += 2) a[r -- ] = s[i], st[i] = true;
	for(int i = 0; i <= n; i ++)
		if(!st[i]) a[l ++] = s[i];

	LL res = 0;
	for(int i = 1; i <= n; i ++) res = max(res, abs(a[i] - a[i - 1]));

	cout << res << "\n";
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