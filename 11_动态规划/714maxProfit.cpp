#include <vector>
#include "limits.h"
using namespace std;

/*
714. 买卖股票的最佳时机含手续费
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

买卖需要手续费。但可以交易无数次。所以可以在122的基础上改。
跟122的唯一区别在于，买的时候不仅是prices[i]，还有fee
状态不变，因为状态是动态变量，而fee是静态信息

如果在更通用的188题上改，那区别在于，最后一步求目标值。f[n][0][k] - k * fee

*/


class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
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
            f[i][1] = max(f[i][1], f[i - 1][0] - prices[i] - fee); // -fee
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