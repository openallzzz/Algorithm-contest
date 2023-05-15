#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int main() {
    vector<PII> a(26);

    int n;
    cin >> n;
    while(n --) {
        char name;
        int r, c;
        cin >> name >> r >> c;
        a[name - 'A'] = {r, c};
    }

    string op;
    while(cin >> op) {
        if(op.size() == 1) cout << 0 << "\n";
        else {
            int res = 0;
            stack<PII> stk;
            for(int i = 0; i < op.size(); i ++) {
                if(op[i] >= 'A' && op[i] <= 'Z') {
                    stk.push(a[op[i] - 'A']);
                } else if(op[i] == ')') {
                    auto y = stk.top(); stk.pop();
                    auto x = stk.top(); stk.pop();
                    if(x.second != y.first) {
                        cout << "error" << "\n";
                        res = 0;
                        break;
                    } else {
                        res += x.first * x.second * y.second;
                        stk.push({x.first, y.second}); // 新矩阵
                    }
                } else ;
            }

            if(res > 0) cout << res << "\n";
        }
    }

    return 0;
}