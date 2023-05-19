#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n;

int dis[N];

void bfs() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 1;
    deque<LL> q;
    q.push_back(1);
    while (q.size()) {
        int t = q.front(); q.pop_front();
        if (dis[t * 2 % n] > dis[t]) // 乘2 1的个数不变
            dis[t * 2 % n] = dis[t], q.push_front(t * 2 % n);
        if (dis[(t + 1) % n] > dis[t] + 1) // 
            dis[(t + 1) % n] = dis[t] + 1, q.push_back((t + 1) % n);
    }
    cout << dis[0] << endl;
}

signed main()
{
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << n << endl;
        return 0;
    }
    bfs();
    return 0;
}