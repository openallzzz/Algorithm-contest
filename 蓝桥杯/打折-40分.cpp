#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int n, m;
struct store {
    int l, r, p, cnt; // cnt作用不大
    unordered_map<int, int> record;
}a[N];

int main() {
    cin >> n >> m;

    int up = 0, down = 1e9;
    for(int i = 0; i < m; i ++) {
        cin >> a[i].l >> a[i].r >> a[i].p >> a[i].cnt;
        up = max(up, a[i].r);
        down = min(down, a[i].l);
        for(int j = 0; j < a[i].cnt; j ++) {
            int id, price;
            cin >> id >> price;
            if(a[i].record.count(id)) {
                price = min(price, a[i].record[id]); // 商店里可以卖同种商品
            }
            a[i].record[id] = price;
        }
    }

    LL res = 1e18;
    for(int i = down; i <= up; i ++) { // 枚举这一天购买所有物品
        LL sum = 0;
        for(int j = 1; j <= n; j ++) { // 枚举第i天第j种物品的最低价
            LL miV = 1e9;
            for(int k = 0; k < m; k ++) {
                if(a[k].l <= i && a[k].r >= i) {
                    if(a[k].record.count(j)) miV = min(miV, (LL)(a[k].p * a[k].record[j]) / 100);
                } else {
                    if(a[k].record.count(j)) miV = min(miV, (LL)a[k].record[j]);
                }
            }
            sum += miV;
        }
        res = min(res, sum);
    }

    cout << res << "\n";
    return 0;
}