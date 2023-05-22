#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    int T;
    cin >> T;
    while(T --) {
        cin >> n >> m;

        bool flag = true;
        for(int i = 1; i <= m; i ++) {
            if(n % i != i - 1) {
                flag = false;
                break;
            }
        }

        if(!flag) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}