#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, x, y;
string s;

int main() {
    cin >> n >> x >> y;
    cin >> s;

    int res = 0; // 连续的0组成的段的数量
    bool flag = false; // 当前位置的前一个位置是否是字符 ：’0‘
    for(char c : s) {
        if(c == '0') {
            if(!flag) res ++ ;
            flag = true;
        } else flag = false;
    }

    if(!res) cout << 0 << "\n";
    else cout << (res - 1) * 1ll * min(x, y) + 0ll + y << "\n";

    return 0;
}