#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>  
#include <vector>
#include <queue>                            

using namespace std;

const int N = 30;

int n, m, flag, c;
vector<int> cnt(N);
bool st[N];

void top_sort(int u, unordered_map<char, vector<char>>& g) {
    vector<int> bak(N);
    for(int i = 0; i < N; i ++) bak[i] = cnt[i];

    queue<int> q;
    for(int i = 0; i < n; i ++) {
        if(bak[i] == 0 && st[i]) q.push(i);
    }

    string res;
    bool unique = true;
    while(q.size()) {
        if(q.size() > 1) unique = false;
        int t = q.front(); q.pop();
        res += 'A' + t;
        for(auto ne : g[t + 'A']) {
            if(-- bak[ne - 'A'] == 0) q.push(ne - 'A');
        }
    }

    if(res.size() < c) {
        flag = 2;
        printf("Inconsistency found after %d relations.\n", u + 1);
    } 

    if(res.size() == n && unique) {
        flag = 1;
        printf("Sorted sequence determined after %d relations: %s.\n", u + 1, res.c_str());
    }
}

int main() {
    while(cin >> n >> m, n || m) {
        for(int i = 0; i < N; i ++) st[i] = false;
        for(int i = 0; i < N; i ++) cnt[i] = 0;
        unordered_map<char, vector<char>> g;

        c = 0, flag = 0;
        for(int i = 0; i < m; i ++) {
            string line;
            cin >> line;
            char a = line[0], b = line.back();
            if(!st[a - 'A']) c ++, st[a - 'A'] = true;
            if(!st[b - 'A']) c ++, st[b - 'A'] = true;

            g[a].push_back(b);
            cnt[b - 'A'] ++ ;

            if(flag) continue;
            top_sort(i, g);
        }

        if(!flag) {
            printf("Sorted sequence cannot be determined.\n");
        }
    }

    return 0;
}