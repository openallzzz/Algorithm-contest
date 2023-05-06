#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void get(vector<int> nums) {
    int n = nums.size();
    vector<int> f(n + 1);

    int res = 0;
    for(int i = 1; i <= n; i ++) {
        f[i] = 1;
        for(int j = 1; j < i; j ++) {
            if(nums[j - 1] < nums[i - 1]) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }

    cout << res << "\n";
}

int main() {
    int x;
    bool flag = false;
    while(true) {
        vector<int> nums;
        while(cin >> x) {
            if(x == 0) flag = true;
            nums.push_back(x);
            if(cin.get() == '\n') break;
        }

        if(flag) break;
        get(nums);
    }

    return 0;
}