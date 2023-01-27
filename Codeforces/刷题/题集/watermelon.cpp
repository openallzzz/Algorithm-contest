#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    for(int i = 2; i < w; i += 2) {
        if(w - i > 0 && (w - i) % 2 == 0) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
    return 0;
}