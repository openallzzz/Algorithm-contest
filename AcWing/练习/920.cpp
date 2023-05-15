#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
vector<int> g[N];
int dist[N];

int main() {
    cin >> m >> n;

    string p;
    getline(cin, p);  // 读入一行内容前，需要先将文件结束符读走，以免影响数据正确性
    while(m --) {
        getline(cin, p);
        p += ' ';

        vector<int> path;
        int cur = 0;
        for(char c : p) {
            if(c == ' ') {
                path.push_back(cur);
                cur = 0;
            } else cur = cur * 10 + c - '0';
        }
        
        for(int i = 0; i < path.size(); i ++) {
            for(int j = i + 1; j < path.size(); j ++) {
                g[path[i]].push_back(path[j]);
            }
        }
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> que;
    que.push(1);

    while(que.size()) {
        auto tt = que.front(); que.pop();
        for(auto& ne : g[tt]) {
            if(dist[ne] > dist[tt] + 1) {
                que.push(ne);
                dist[ne] = dist[tt] + 1;
            }
        }
    }

    if(dist[n] == INF) puts("NO");
    else cout << dist[n] - 1 << "\n";

    return 0;
}