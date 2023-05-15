#include <bits/stdc++.h>

using namespace std;

bool cinT = false; // 多组数据

typedef long long LL;

const int N = 1e5 + 10;

LL exgcd(LL a, LL b, LL& x, LL& y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

void solve() {
	int n;
	cin >> n;
	
	bool has_ans = true;
	LL a1, m1;
	cin >> a1 >> m1;
	
	for(int i = 0; i < n - 1; i ++) {
		LL a2, m2;
		cin >> a2 >> m2;
		
		LL k1, k2;
		LL d = exgcd(a1, a2, k1, k2);
		if((m2 - m1) % d) {
			has_ans = false;
		}
		
		k1 *= (m2 - m1) / d;
		LL t = a2 / d;
		k1 = (k1 % t + t) % t;
		
		m1 = a1 * k1 + m1;
		a1 = abs(a1 / d * a2);
	}
	
	if(has_ans) {
		cout << (m1 % a1 + a1) % a1 << "\n";
	} else cout << "-1" << "\n";
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

