#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    while(m --) {
        int l, r;
        char old_char, new_char;
        cin >> l >> r >> old_char >> new_char;
        for(int i = l - 1; i <= r - 1; i ++) {
            if(s[i] == old_char) s[i] = new_char;
        }
    }

    cout << s << "\n";
    return 0;
}