#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    string s;
    cin >> s;
    int res = 0;
    for(char t : s) {
        if(t == '1') res += a;
        if(t == '2') res += b;
        if(t == '3') res += c;
        if(t == '4') res += d;
    }

    cout << res << "\n";
    return 0;
}