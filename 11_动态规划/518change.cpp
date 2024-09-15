#include <vector>
using namespace std;

/*
518. 零钱兑换 II
https://leetcode-cn.com/problems/coin-change-2/

零钱兑换就是个完全背包问题

有那么多种零钱，所以，零钱=物品
要凑到这么多钱，所以，面值=体积
取1个就多1枚硬币，所以，价值/代价=1
要最少硬币数量，所以，最小化价值

这里求的不是硬币数量，求的是方案数。本质是 动态规划+计数
状态: f[i,j]表示，前i种硬币凑成金额j的方案数，不关心具体是哪几种
状态转移:
    还没选过第i种硬币: f[i,j] = f[i-1,j]
    选第i种硬币: f[i,j] += f[i,j-coins[i]] --计数，就是累加
初值: f[i,0] = 1
目标: max{f[i,amount]}, 0<=i<n
*/

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // 下标从1开始
        coins.insert(coins.begin(), 0);

        // 定义状态，合法状态初始化
        vector<int> f(amount + 1, 0);
        f[0] = 1;

        // for物品
        for (int i = 1; i <= n; ++i) {
            // for体积。完全背包，正序遍历
            for (int j = coins[i]; j <= amount; ++j) {
                f[j] += f[j - coins[i]];
            }
        }

        return f[amount];
    }
};