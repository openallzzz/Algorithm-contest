#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    string t = s;
    sort(t.begin(), t.end());
    
    int res = 0;
    do {
        if(t == s) break;
        res ++ ;
    } while(next_permutation(t.begin(), t.end()));

    cout << res << "\n";
    return 0;
}