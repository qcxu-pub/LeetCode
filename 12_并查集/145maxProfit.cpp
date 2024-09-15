#include <algorithm>
using namespace std;
#include <iostream>
#include <cstdio>

/*
145. 超市
https://www.acwing.com/problem/content/147/

利用路径压缩的想法，解决链的形状
贪心: 先卖利润大
就卡在临过期之前卖，这样对其他商品的影响最小。如果想要卖的那天被占用了，就往前找最近的空 --决策包容性

并查集维护时间的占用情况，找到deadline之前的最近空闲日
如果不用并查集，冗余在这里: 
d 1 2 3 ... i-2 i-1 i i+1 i+2 i+3 ... n
             空  空 有
             ^   ^
             |___|__|
比如第i天有3个要过期，一个就安排在第i天，还有两个要往前找，往前找空格子的过程是重复的，时间复杂度O(n^2)
找结点的过程像个链，链本身是一个特殊的树
所以并查集利用路径压缩的思想，是把空闲日作为根，后面的日子都指向这个根，这样查找时间复杂度O(n)

*/

pair<int, int> a[10000];  // 最多10000条数据, {profit,day}
int n;                    // 0 <= n <= day_max = 10000
int fa[10001];            // n 的取值有10001个

// 返回根节点
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
    // 输入数据
    while (cin >> n) {
        
        // 注意所有的代码所有的代码都写在while循环里面。因为是批量测试的。。

        for (int i = 0; i < n; ++i) {
            // profit, day
            cin >> a[i].first >> a[i].second;
        }

        // sort by profit
        sort(a, a + n);

        // 初始化并查集
        for (int i = 0; i <= 10000; ++i)
            fa[i] = i;

        // ans
        int ans = 0;
        // for from max profit
        for (int i = n - 1; i >= 0; --i) {
            int profit = a[i].first;
            int day = a[i].second;
            int lastAvailableDay = find(day);  //找day的根节点，就是最近一天还空闲的day
            // 之前有空
            if (lastAvailableDay > 0) {
                ans += profit;
                fa[lastAvailableDay] = lastAvailableDay - 1;  //往前找。lastAvailableDay已经被用掉了
            }
        }
        cout << ans << endl;
    }
}