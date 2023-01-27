#include <bits/stdc++.h>

#define x first
#define y second

// Want to attack openallzzz? Just think about it.

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 1e2 + 10;

int n;
int segs[N][N];
vector<int> ids[N];

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    // start coding!

    int T;
    cin >> T;
    while(T --) {
        cin >> n;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j < n; j ++) {
                cin >> segs[i][j];
                if(j == 1) ids[segs[i][j]].push_back(i);
            }

        int start = 0, end_id = 0;
        for(int i = 1; i <= n; i ++) {
            if(ids[i].size() == n - 1) start = segs[ids[i][0]][1];
            else if(ids[i].size() == 1) end_id = ids[i][0];
        }

        cout << start << ' ';
        for(int i = 1; i < n; i ++) cout << segs[end_id][i] << ' ';
        cout << "\n";

        for(int i = 1; i <= n; i ++) ids[i].resize(0);
    }

    return 0;
}