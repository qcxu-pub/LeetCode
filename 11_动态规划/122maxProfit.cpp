#include <vector>
#include "limits.h"
using namespace std;

/*
122. 买卖股票的最佳时机 II
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

可以交易无数次。之前用贪心做过。这里用动规做

状态只有 i,j 两个变量
1.状态
  f[i,j] 表示第 i 天结束时，持有 j 股股票的最大收益 (j = 0 or 1)
  只关心maxProfit是多少，方案无所谓 --> 最优子结构
2.状态转移方程
  买: f[i,1] = max(f[i,1], f[i-1,0] - price[i])
  卖: f[i,0] = max(f[i,0], f[i-1,1] + price[i])
  啥也不干: f[i,j] = max(f[i,j], f[i-1,j])
3.边界
  合法起点f[0,0]=0
  其余点都是负无穷，因为要求maxProfit
4.目标
  f[n,0]
5.时间复杂度
  O(n)

*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 0.下标从1开始
        prices.insert(prices.begin(), 0);

        // 1.定义状态，初始化边界
        vector<vector<int> > f(n + 1, vector<int>(2, INT_MIN));  // 要 n+1
        f[0][0] = 0;

        // 2.遍历所有状态
        for (int i = 1; i <= n; ++i) {
            // 3.更新决策
            // 3.1 买
            f[i][1] = max(f[i][1], f[i - 1][0] - prices[i]);
            // 3.2 卖
            f[i][0] = max(f[i][0], f[i - 1][1] + prices[i]);
            // 3.3 啥也不干
            for (int j = 0; j < 2; ++j)
                f[i][j] = max(f[i][j], f[i - 1][j]);
        }

        // 4.目标
        return f[n][0];
    }
};


/*
再对比一下上次的贪心算法

比如当前的状态是不持仓，那从动规的代码里面可以看到，有两种方式可以转移到这里：
1. 卖: f[i - 1][1] + prices[i] = f[i - 1][0] - prices[?] + prices[i]，其中 ? 是交钱买股票的那天
2. 啥也不干: f[i - 1][0]
那这俩谁大，谁大要谁。这主要取决于 pricediff = prices[i] - prices[?]
如果pricediff > 0，说明涨了，就卖；否则就不动

这样就到了贪心的思想了
动规是全局算的，但贪心是局部算的。动规更容易拓展。

*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};


/*
优化空间: 滚动数组 (见README.md 思考4)
& 的优先级低于 +/-
空间复杂度: O(n) --> O(1)
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 0.下标从1开始
        prices.insert(prices.begin(), 0);

        // 1.定义状态，初始化边界。滚动数组，空间开2就可以了
        vector<vector<int> > f(2, vector<int>(2, -1e9));
        f[0][0] = 0;

        // 2.遍历所有状态
        for (int i = 1; i <= n; ++i) {
            // 初始化复用空间
            f[i & 1][0] = -1e9;
            // 3.更新决策
            // 3.1 买
            f[i & 1][1] = max(f[i & 1][1], f[i - 1 & 1][0] - prices[i]);
            // 3.2 卖
            f[i & 1][0] = max(f[i & 1][0], f[i - 1 & 1][1] + prices[i]);
            // 3.3 啥也不干
            for (int j = 0; j < 2; ++j)
                f[i & 1][j] = max(f[i & 1][j], f[i - 1 & 1][j]);
        }

        // 4.目标
        return f[n & 1][0];
    }
};