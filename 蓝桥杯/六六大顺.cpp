#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;

vector<char> add(vector<char> A, vector<char> B) {
    vector<char> C;
    for(int i = 0, r = 0; i < A.size() || i < B.size() || r; i ++) {
        if(i < A.size()) r += A[i] - '0';
        if(i < B.size()) r += B[i] - '0';
        C.emplace_back(r % 10 + '0'); r /= 10;
    }
    return C;
}

vector<char> sub(vector<char> A, vector<char> B) {
    vector<char> C;
    for(int i = 0, r = 0; i < A.size(); i ++) {
        if(i < A.size()) r = (A[i] - '0') - r;
        if(i < B.size()) r = r - (B[i] - '0');
        C.emplace_back((r + 10) % 10 + '0');
        if(r < 0) r = 1;
        else r = 0;
    }
    while(C.size() > 1 && C.back() == '0') C.pop_back();
    return C;
}

vector<char> mult(vector<char> A, int b) {
    vector<char> C;
    for(int i = 0, r = 0; i < A.size() || r; i ++) {
        if(i < A.size()) r += (A[i] - '0') * b;
        C.emplace_back(r % 10 + '0'); r /= 10;
    }
    while(C.size() > 1 && C.back() == '0') C.pop_back();
    return C;
}

vector<char> div(vector<char> A, int b) {
    vector<char> C;
    for(int i = A.size() - 1, r = 0; i >= 0; i --) {
        r = r * 10 + (A[i] - '0');
        C.emplace_back(r / b + '0'); r %= b;
    }

    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == '0') C.pop_back();
    return C;
}

void print(vector<char> A) {
    for(int i = A.size() - 1; i >= 0; i --) {
        printf("%c", A[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<char> A(1, '0'), B(1, '0'), C, res;
    for(int i = 0, r = 0; i < n * 2; i ++) {
        A.emplace_back(r + '0'); r ^= 1;
    }

    for(int i = 0; i < n; i ++) {
        B.emplace_back('2');
    }

    while(n) C.emplace_back(n % 10 + '0'), n /= 10;

    res = div(mult(add(sub(A, B), C), 4), 9);

    print(res);
    return 0;
}