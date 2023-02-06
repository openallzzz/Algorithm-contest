#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e6 + 10;

int n;
LL sum;
LL s[N];

void solve() {
	cin >> n >> sum;
	for(int i = 1; i <= n; i ++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	
	int res = 0;
	for(int i = 1; i < n; i ++) {
		int l = 0, r = i;
		while(l < r) {
			int mid = l + r >> 1;
			if(s[i] - s[mid] <= sum) r = mid;
			else l = mid + 1;
		}
		
		if(s[i] - s[r] > sum) continue;
		
		int x = (i - r);
		
		l = i, r = n;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(s[mid] - s[i] <= sum) l = mid;
			else r = mid - 1;
		}
		
		if(s[r] - s[i] > sum) continue;
		
		int y = (r - i);
		res = max(res, 2 * min(x, y));
	}
	
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
