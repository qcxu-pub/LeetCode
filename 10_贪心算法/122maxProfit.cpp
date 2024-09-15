#include <vector>
using namespace std;

/*
122. 买卖股票的最佳时机 II
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

往后看一步，拓展决策范围，就知道现在怎么做事最好的
当前持有股票卖不卖？明天涨，那今天就不卖了
当前没有股票买不买？明天涨，那今天就买
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