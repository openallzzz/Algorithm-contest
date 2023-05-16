#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL tot = 0; // Byte

void solve(string s) {
    vector<string> strs;
    s = ',' + s + ',';
    for(int i = 0, prev = -1; i < s.size(); i ++) {
        if(s[i] == ',') {
            if(prev != -1) strs.push_back(s.substr(prev + 1, i - prev - 1));
            prev = i;
        }
    }

    bool arr = s.find("[]") != -1;
    bool f1 = s.find("int") != -1;
    bool f2 = s.find("long") != -1;
    bool f3 = s.find("String") != -1;

    for(string s : strs) {
        if(f1) {
            if(arr) {
                LL t = 0;
                for(int i = s.find('='); i < s.size(); i ++) {
                    if(isdigit(s[i])) t = t * 10 + (s[i] - '0');
                }
                tot += t * 4;
            } else {
                tot += 4;
            }
        } else if(f2) {
            if(arr) {
                LL t = 0;
                for(int i = s.find('='); i < s.size(); i ++) {
                    if(isdigit(s[i])) t = t * 10 + (s[i] - '0');
                }
                tot += t * 8;
            } else {
                tot += 8;
            }
        } else if(f3) {
            int l = -1, r = -1;
            for(int i = s.find('='); i < s.size(); i ++) {
                if(s[i] == '"') {
                    if(l == -1) l = i;
                    else r = i;
                }
            }

            tot += max(0, r - l - 1);
        }
    }
}

int main() {
    int T;
    cin >> T;
    getchar(); // 读取无用的换行符
    string line;
    while(T -- ) {
        getline(cin, line);
        solve(line);
    }

    LL G = tot / (1024 * 1024 * 1024);
    if(G) {
        cout << G << "GB";
    }

    tot %= (1024 * 1024 * 1024);

    LL M = tot / (1024 * 1024);
    if(M) {
        cout << M << "MB";
    }

    tot %= (1024 * 1024);

    LL K = tot / (1024);
    if(K) {
        cout << K << "KB";
    }

    tot %= 1024;

    LL B = tot;
    if(B) {
        cout << B << "B";
    }

    return 0;
}