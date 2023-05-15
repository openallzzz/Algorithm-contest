#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int h, e[N], ne[N], idx;

void init() {
    h = -1, idx = 0;
}

void push_front(int x) {
    e[idx] = x, ne[idx] = h, h = idx ++;
}

void insertByIdx(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
}

void deleteByIdx(int k) {
    ne[k] = ne[ne[k]];
}

void solve() {
    cin >> n;
    char op;
    int k, x;
    init();
    while (n -- ) {
        cin >> op;
        if (op == 'H') {
            cin >> x;
            push_front(x);
        } else if(op == 'D') {
            cin >> k;
            if(!k) h = ne[h];
            else deleteByIdx(k - 1);
        } else if(op == 'I') {
            cin >> k >> x;
            insertByIdx(k - 1, x);
        }
    }

    for(int i = h; i != -1; i = ne[i]) cout << e[i] << " ";
    cout << "\n";
}

int main() {
    cin.tie(0); cout.tie(0);
    std::ios::sync_with_stdio(false);

    solve();
    return 0;
}