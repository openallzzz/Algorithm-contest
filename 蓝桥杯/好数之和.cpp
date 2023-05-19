#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

LL res = 0;
int L, R;
vector<string> level[6];
unordered_set<string> S;

void dfs(vector<string>& v, int u, string path, int n) {
    if(u == n) {
        v.push_back(path);
        return ;
    }

    for(int i = 0; i < 10; i ++) {
        path += (i + '0');
        dfs(v, u + 1, path, n);
        path.pop_back();
    }
}

bool check(string& s) {
    int idx = 0;
    while(s[idx] == '0') idx ++ ;
    s = s.substr(idx);
    if(s.size() >= 10) return false;
    int n = stoi(s);
    return n >= L && n <= R;
}

void solve(int l, int r) {
    if(l + r + 4 >= 10) return ;

    vector<string> ll = level[l], rr = level[r];
    string base = "2022";
    for(auto& a : ll)
        for(auto& b : rr) {
            string t = a + base + b;
            if(check(t))
                S.insert(t);
        }
}

int main() {
    cin >> L >> R;

    if(R < 2022) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < 6; i ++) level[i].push_back("");
    for(int i = 1; i <= 5; i ++) dfs(level[i], 0, "", i);

    for(int i = 0; i <= 5; i ++)
        for(int j = 0; i + j <= 5; j ++)
            solve(i, j);

    for(string s : S) {
        res += stoi(s);
    }

    cout << res << "\n";
    return 0;
}