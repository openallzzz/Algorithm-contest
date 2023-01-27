#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int hp[N];
int main() {
    int T;
    cin >> T;
    while(T --)
    {
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> hp[i];
        sort(hp, hp + n);

        int len = 0, flag = 1;
        for(int i = 0; i < n; i ++) {
            if(hp[i] == 1 && flag) len ++;
            if(hp[i] > 1) flag = 0;
        }
        cout << n - len + (len / 2 + len - (len / 2) * 2) << endl;
    }
    return 0;
}