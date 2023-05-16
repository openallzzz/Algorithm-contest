#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int x, y;
int record[N];

int main() {
    scanf("%d,%d", &x, &y);

    string res;
    res += (x / y) + '0';
    x %= y;

    if(x == 0) {
        res += ".0";
    } else {
        res += '.';
        bool is_circle = false;
        string t;

        int idx = 1, l = 0, r = 0;
        while(true) {
            if(x < y) x *= 10;
            if(record[x] != 0) {
                is_circle = true;
                l = record[x] - 1;
                r = idx - 2;
                break;
            }

            record[x] = idx ++ ;

            t += x / y + '0';
            x %= y;

            if(x == 0) break;
        }

        if(is_circle) {
            string left = t.substr(0, l);
            string right = t.substr(l, r - l + 1);
            t = left + '[' + right + ']';
        }
        res += t;
    }

    cout << res << "\n";
    return 0;
}