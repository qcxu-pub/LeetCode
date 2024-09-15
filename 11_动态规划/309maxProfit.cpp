#include <vector>
#include "limits.h"
using namespace std;

/*
309. 最佳买卖股票时机含冷冻期
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

有冷冻期。卖了之后要冷冻一天才能买。但可以买卖无数次。所以可以在122的基础上改。

状态相比122多了一个变量 i,j,l
1.状态
  f[i,j,l] 表示第 i 天结束时，持有 j 股股票的收益 (j = 0 or 1)，当前是否处于冷冻期 l (l = 0 or 1)
2.状态转移方程
  买: f[i,1,0] = max(f[i,1,0], f[i-1,0,0] - prices[i]) --> 只有l=0时有，买完不会进入冷冻期
  卖: f[i,0,1] = max(f[i,0,1], f[i-1,1,0] + prices[i]) --> 卖完就冷冻了
  啥也不干: f[i,j,0] = max(f[i,j,0], f[i-1,j,l])
3.边界
  合法起点 f[0,0,0] = 0
  其余点都是负无穷，因为要求maxProfit
4.目标
  max(f[n,0,0],f[n,0,1])

*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 0.下标从1开始
        prices.insert(prices.begin(), 0);

        // 1.定义状态，初始化边界
        vector<vector<vector<int> > > f(n + 1, vector<vector<int> >(2, vector<int>(2, INT_MIN)));
        f[0][0][0] = 0;

        // 2.遍历所有状态
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int l = 0; l < 2; ++l) {
                    // 3.更新决策
                    f[i][1][0] = max(f[i][1][0], f[i - 1][0][0] - prices[i]);
                    f[i][0][1] = max(f[i][0][1], f[i - 1][1][0] + prices[i]);
                    f[i][j][0] = max(f[i][j][0], f[i - 1][j][l]);
                }
            }
        }

        // 4.目标
        return max(f[n][0][0], f[n][0][1]);
    }
};


/*
上面的思路是：入边-点
下面的思路是：点-出边，用列表法 (见README.md 思考3)
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 0.下标从0开始
        prices.insert(prices.begin(), 0);

        // 1.定义状态，初始化边界
        vector<vector<vector<int> > > f(n + 1, vector<vector<int> >(2, vector<int>(2, -1e9)));
        f[0][0][0] = 0;

        // 2.遍历所有状态
        // 从当前点往后找，所以i从0开始
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int l = 0; l < 2; ++l) {
                    // 当前状态不合法
                    if (f[i][j][l] == -1e9)
                        continue;
                    // 下一天干啥
                    if (j == 0 && l == 0)
                        f[i + 1][1][0] = max(f[i + 1][1][0], f[i][j][l] - prices[i + 1]);
                    if (j == 1 && l == 0)
                        f[i + 1][0][1] = max(f[i + 1][0][1], f[i][j][l] + prices[i + 1]);
                    f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][l]);
                }
            }
        }

        // 4.目标
        return max(f[n][0][0], f[n][0][1]);
    }
};


/*
优化空间：滚动数组。有点像滑动窗口 (见README.md 思考4)
所有的 i 变成 (i & 1)。& 优先级小于+/-，所以可以不用()
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 0.下标从0开始
        prices.insert(prices.begin(), 0);

        // 1.定义状态，初始化边界。滚动数组第一维只要2这么长
        vector<vector<vector<int> > > f(2, vector<vector<int> >(2, vector<int>(2, -1e9)));
        f[0][0][0] = 0;

        // 2.遍历所有状态
        // 从当前点往后找，所以i从0开始
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int l = 0; l < 2; ++l) {
                    // 当前状态不合法
                    if (f[i & 1][j][l] == -1e9)
                        continue;
                    // 下一天干啥
                    if (j == 0 && l == 0)
                        f[(i + 1) & 1][1][0] = max(f[(i + 1) & 1][1][0], f[i & 1][j][l] - prices[i + 1]);
                    if (j == 1 && l == 0)
                        f[(i + 1) & 1][0][1] = max(f[(i + 1) & 1][0][1], f[i & 1][j][l] + prices[i + 1]);
                    f[(i + 1) & 1][j][0] = max(f[(i + 1) & 1][j][0], f[i & 1][j][l]);
                    // 复用空间的初始化
                    f[i & 1][j][l] = -1e9;
                }
            }
        }

        // 4.目标
        return max(f[n & 1][0][0], f[n & 1][0][1]);
    }
};