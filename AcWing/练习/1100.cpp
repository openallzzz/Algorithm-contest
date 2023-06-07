#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int dist[N * 2];

int main() {
    cin >> n >> m;

    queue<int> q;
    q.push(n);

    memset(dist, 0x3f, sizeof dist);
    dist[n] = 0;

    while(q.size()) {
        int u = q.front(); q.pop();

        if(u == m) break;

        if(dist[u + 1] > dist[u] + 1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }

        if(u - 1 >= 0 && dist[u - 1] > dist[u] + 1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }

        if(u + u < N && dist[u + u] > dist[u] + 1) {
            dist[u + u] = dist[u] + 1;
            q.push(u + u);
        }
    }

    cout << dist[m] << "\n";
    return 0;
}