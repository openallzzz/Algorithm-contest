#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string s;

vector<int> div(vector<int>& A, int b, int& r)
{
    vector<int> C;

    for(int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back(); // 除去前导0

    return C;
}

// 判断是否有 A >= B 
bool cmp(vector<int>& A, vector<int>& B)
{
    if(A.size() != B.size()) return A.size() > B.size();
    else{
        for(int i = A.size() - 1; i >= 0; i--)
        {
            if(A[i] != B[i]) return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10); // 按位数从低到高排序4123输出的是3214
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

void print(vector<int> num) {
    for(int i = num.size() - 1; i >= 0; i --) cout << num[i];
    cout << "\n";
}

void solve() {
    vector<int> A;
    for(int i = s.size() - 1; i >= 0; i --) A.push_back(s[i] - '0');

    int r = 0;
    vector<int> res = div(A, 2, r); // N / 2 下取整
    if(r == 1) {
        print(res);
    } else {
        r = 0;
        vector<int> b = div(res, 2, r);

        if(r == 1) {
            vector<int> y; y.push_back(1);
            res = sub(res, y);
            print(res);
        } else {
            vector<int> y; y.push_back(2);
            if(!cmp(res, y)) swap(res, y);
            res = sub(res, y);
            print(res);
        }
    }
}

int main() {
    while(cin >> s) {
        solve();
    }
    return 0;
}