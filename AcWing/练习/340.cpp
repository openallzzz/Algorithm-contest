#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 20010;

int n, p, k;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

bool check(int X) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);

    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size()) {
        auto t = heap.top(); heap.pop();

        if(st[t.second]) continue;
        st[t.second] = true;

        for(int i = h[t.second]; i != -1; i = ne[i]) {
            int j = e[i], v = w[i] > X;
            if(dist[j] > dist[t.second] + v) {
                dist[j] = dist[t.second] + v;
                heap.push({dist[j], j});
            }
        }
    }

    return dist[n] <= k;
}

int main() {
    cin >> n >> p >> k;

    int up = 0;
    memset(h, -1, sizeof h);
    while(p --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
        up = max(up, c);
    }

    int l = 0, r = up;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    if(check(r)) cout << r << "\n";
    else cout << -1 << "\n";

    return 0;
}