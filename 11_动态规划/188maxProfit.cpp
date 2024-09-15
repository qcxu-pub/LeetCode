#include <vector>
#include "limits.h"
using namespace std;

/*
188. 买卖股票的最佳时机 IV
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

最多完成 c 笔交易 --可以同时解决 121,122,123 题
121: c=1 --> 还有一种思路，固定i，求前缀min。之前做过
122: c=n --> 这样时间复杂度就变成 O(n^2) 了，122的做法时间复杂度是 O(n)。但这个逻辑是对的
123: c=2

状态有 i,j,k 三个变量
1.状态
  f[i,j,k] 表示第 i 天结束时，已交易 k 次，持有 j 股股票的最大收益 (j = 0 or j = 1)
2.状态转移方程
  买: f[i,1,k] = max(f[i,1,k], f[i-1,0,k-1] - prices[i])
  卖: f[i,0,k] = max(f[i,0,k], f[i-1,1,k] + prices[i])
  啥也不干: f[i,j,k] = max(f[i,j,k], f[i-1,j,k])
3.边界
  合法起点f[0,0,0]=0
  其余点都是负无穷，因为要求的是maxProfit
4.目标
  max{f[n,0,k]}, 其中 0<=k<=c
5.时间复杂度
  O(n*c) -- 0<=i<n, 0<=k<=c, 0<=j<=1

*/

class Solution {
   public:
    int maxProfit(int c, vector<int>& prices) {
        int n = prices.size();
        // 0.下标从1开始
        prices.insert(prices.begin(), 0);

        // 1.定义状态，初始化边界
        vector<vector<vector<int> > > f(n + 1, vector<vector<int> >(2, vector<int>(c + 1, -1e9)));
        f[0][0][0] = 0;

        // 2.遍历所有状态
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k <= c; ++k) {
                    // 3.更新决策。注意边界
                    if (k >= 1)
                        f[i][1][k] = max(f[i][1][k], f[i - 1][0][k - 1] - prices[i]);
                    f[i][0][k] = max(f[i][0][k], f[i - 1][1][k] + prices[i]);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
                }
            }
        }

        // 4.目标
        int ans = INT_MIN;
        for (int k = 0; k <= c; ++k) {
            ans = max(ans, f[n][0][k]);
        }
        return ans;
    }
};