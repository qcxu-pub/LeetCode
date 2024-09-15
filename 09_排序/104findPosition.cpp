#include "bits/stdc++.h"
using namespace std;

/*
104. 货仓选址
https://www.acwing.com/problem/content/description/106/

画图发现，货仓建在哪里合适？中间位置！
就是求中位数
*/

int main() {
    int n;
    int a[100005];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    int pos = a[n / 2];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(pos - a[i]);
    }
    cout << ans << endl;
}