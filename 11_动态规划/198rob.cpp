#include <vector>
using namespace std;

/*
198. 打家劫舍
https://leetcode-cn.com/problems/house-robber/

暴力搜索: 每间房偷还是不偷，一共n间房，这样时间复杂度O(2^n)。还需要限制不能同时偷相邻的房子
要算的是一共n座房屋，那最优子结构就是：前n间房的最大收益 + 第n间房是偷了还是没偷
状态: f[i,j]表示，偷窃前i座房屋，第i座房屋的闯入情况为j(0-未闯入, 1-闯入)时的最大收益
递推1: 从哪里来
    f[i,0] = max(f[i-1,1], f[i-1,0])
    f[i,1] = f[i-1,0] + nums[i]
递推2: 到哪里去
    f[i,0] -> f[i+1,0]
           -> f[i+1,1] + nums[i]
    f[i,1] -> f[i+1,0]
初值: f[0,0] = 0, 其余负无穷
目标: max(f[n,0], f[n,1])
*/

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 0.下标从1开始
        nums.insert(nums.begin(), 0);
        
        // 1.定义状态，初始化边界
        vector<vector<int> > f(n + 1, vector<int>(2, -1e9));
        f[0][0] = 0;

        // 2.遍历所有状态，更新决策
        for (int i = 1; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i];
        }

        // 3.目标
        return max(f[n][0], f[n][1]);
    }
};