#include <vector>
using namespace std;

/*
213. 打家劫舍 II
https://leetcode-cn.com/problems/house-robber-ii/

跟198的区别：198是直线，213是个环
动规对应的状态空间的形状是有向无环图。但这里带环了

那就把环断开。因为不能同时偷首尾，所以拆解成两种情况：不偷首，可以偷尾；可以偷首，不偷尾
两种情况的最优值再取max，就是全局最优解
所以，滚动型DP处理环的方法：两次DP

跟198题一样，f[i,j]表示，偷窃前i座房屋，第i座房屋的闯入情况为j(0-未闯入, 1-闯入)时的最大收益

1.不偷首，可以偷尾
不偷首: f[1,0]=0, f[1,1]=负无穷 --这样f[1,1]就不能成为最优解了 
可以偷尾: 目标是 max(f[n,0],f[n,1])

2.可以偷首，不偷尾
可以偷首: f[1,0]=0, f[1,1]=nums[1]
不偷尾: 目标是 f[n,0]

*/

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // 0.下标从1开始
        nums.insert(nums.begin(), 0);
        // 特殊情况，1个元素成不了环
        if (n == 1)
            return nums[1];  // 因为前面插入了一个元素，下标从1开始了

        // 1.定义状态，初始化边界
        vector<vector<int> > f(n + 1, vector<int>(2, -1e9));

        // 2.1 遍历所有状态 --DP1
        f[1][0] = 0;
        for (int i = 2; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        ans = max(f[n][0], f[n][1]);

        // 2.2 遍历所有状态 --DP2
        f[1][0] = 0;
        f[1][1] = nums[1];
        for (int i = 2; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }
        ans = max(ans, f[n][0]);

        // 3.全局最优解
        return ans;
    }
};