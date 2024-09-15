#include <vector>
#include "limits.h"
using namespace std;

/*
322. 零钱兑换
https://leetcode-cn.com/problems/coin-change/


搜索。状态：剩余金额，已用硬币枚数
贪心。只是搜索的一条路径。还不一定是最优的

动规。搜索为什么慢？搜索每次三个分支，以三的指数级增长。

18 --------> 9 -------> 0
|            |          |
18->17->...->9->8->...->0

上图蛮力搜索会有四条分支，但不是都有用的！
就比如，知道 9->0 这个分支更好，那之后 9->8->7->...->1->0 这个分支完全没用
所以，对于每个“剩余金额”，搜一次，求出“对换这个金额所需的最少硬币枚数”就足够了
把这种最优化方案（硬币枚数最少）作为代表，其他分支全部都砍掉

原始状态：剩余金额，已用硬币枚数。目标：到达终点（0元）
新状态：剩余金额。优化目标：硬币枚数更少
推导关系：兑换n元的最少硬币枚数，有三个分支，[兑换n-1元+兑换1元],[兑换n-9元+兑换9元]+[兑换n-10元+兑换10元]
         即 opt(n) = min(opt(n-1), opt(n-9), opt(n-10)) + 1  --只在代表之间递归
状态 + 最优化目标 + 最优化目标之间具有递推关系 = 最优子结构


实现方式有两种：递推，递归+记忆化搜索
（递推更简单更常用）
*/


/*递推*/
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // 如果是int，后面 opt[i-coin] + 1 会越界
        vector<long long> opt(amount + 1, INT_MAX);
        opt[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    opt[i] = min(opt[i], opt[i - coin] + 1);
                }
            }
        }
        if (opt[amount] == INT_MAX)
            return -1;
        else
            return opt[amount];
    }
};


/*递归 + 记忆化搜索 --自己写的*/
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->target = amount;
        ans = 0;
        opt = vector<int>(amount + 1, -1);
        opt[0] = 0;
        return dfs(amount);
    }

   private:
    vector<int> coins;
    int target;
    int ans;
    vector<int> opt;  // 凑amount金额的方案数

    // 返回的是方案数
    int dfs(int amount) {
        if (amount > target)
            return ans;
        // 搜索过了，有方案
        if (opt[amount] >= 0)
            return opt[amount];
        // 搜索过了，没方案
        if (opt[amount] == -2)
            return -1;

        int best = INT_MAX;
        for (int coin : coins) {
            if (amount >= coin) {
                int cnt = dfs(amount - coin);  // dfs
                if (cnt >= 0) {
                    best = min(best, cnt);
                }
            }
        }
        // 没方案
        if (best == INT_MAX) {
            opt[amount] = -2;
            return -1;
        }
        // 有方案
        opt[amount] = best + 1;
        return best + 1;
    }
};

/*
递归 + 记忆化搜索 --答案

有一个坑：最后取答案是从dfs()返回值拿更容易一些，opt[amount]里拿更麻烦
return ans == INT_MAX ? INT_MAX : ans;
return amount == 0 ? 0 : (opt[amount]==INT_MAX ? -1 : opt[amount]);

1.可能因为amount=0，从未更新过opt[amount]
2.不可能凑成amount时，最后opt[amount]=INT_MAX
*/
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        opt = vector<long long>(amount + 1, -1);
        long long ans = dfs(amount);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }

   private:
    vector<int> coins;
    vector<long long> opt;

    // 返回的是方案数
    int dfs(int amount) {
        if (amount == 0)
            return 0;
        // 没方案
        if (amount < 0)
            return INT_MAX;
        // 搜索了，有方案
        if (opt[amount] != -1)
            return opt[amount];

        opt[amount] = INT_MAX;
        for (int coin : coins) {
            long long cnt = dfs(amount - coin);
            opt[amount] = min(opt[amount], cnt + 1);  // dfs
        }
        return opt[amount];
    }
};