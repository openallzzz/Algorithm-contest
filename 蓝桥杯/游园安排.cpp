#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000010;

string s;
int record[N], n;
string p[N];
string strs[N];

int main() {
    cin >> s; s += 'A';
    for(int i = 0, prev = -1; i < s.size(); i ++) {
        char c = s[i];
        if(c >= 'A' && c <= 'Z') {
            if(prev != -1) {
                strs[n ++ ] = s.substr(prev, i - prev);
            }
            prev = i;
        }
    }

    int len = 0;
    for(int i = 0; i < n; i ++) {
        string t = strs[i];
        int l = 0, r = len;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(p[mid] < t) l = mid;
            else r = mid - 1;
        }

        if(p[r] >= t) continue;

        p[r + 1] = t;
        len = max(len, r + 1);
        record[i] = r + 1; // 当前位置i是长度为r + 1的上升子序列的最后一个字符串的下标
    }

    vector<string> res;
    for(int i = n - 1; i >= 0; i --) {
        if(len <= 0) break;
        if(record[i] == len) {
            res.push_back(strs[i]);
            len -- ;
        }
    }

    for(int i = res.size() - 1; i >= 0; i --) cout << res[i];
    return 0;
}