#include <vector>
using namespace std;

/*
312. 戳气球
https://leetcode-cn.com/problems/burst-balloons/

戳哪个？人工模拟一下。
1.先戳哪个？
先戳第p个，那这时获得的硬币数=f[p-1,p+1]
删除第p个，下一个最优化问题就是 f[l,p-1], f[p+1,r]
但第i个被戳破以后，第 p-1 相邻的不再是 p，而是 p+1。这样就没有最优子结构了
所以这个方法行不通

2.最后戳哪个？
正着不行，倒着看下。就是递归的本层逻辑放在开始还是结束的区别。
如果先戳[l,p-1] 和 [p+1,r]，最后戳p
比如p左边最后一次戳的情况，比如戳的是第i个，那i的左边一定是边界，i的右边一定是p。这些都是固定的
这样才形成了最优子问题

动态规划
阶段: 区间长度
状态: f[l,r] 表示戳破[l,r]之间所有气球，所获硬币的最大数量。l-1, r+1 都是超界的
决策: 在l和r上找p，最后一个戳的是p, f[l,r] = max{f[l,p-1] + f[p+1,r] + nums[p] * nums[l-1] * nums[r+1]}
      经过max以后，就转移到 f[l,r] 了
初值: f[l,r] = 0 if l > r，戳完了
目标: f[1,n]
时间复杂度: for l for r --> O(n^2)
           每个区间有(r-l+1)个分支，用来找p --> O(n)
           所以最快情况的时间复杂度是 O(n^3)
空间复杂度: l,r --> O(n^2)

*/


/*
for循环递推
*/

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // 越界
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int> > f(n + 2, vector<int>(n + 2, 0));
        // 阶段。区间动态规划，最外层是循环区间长度
        for (int len = 1; len <= n; ++len) {
            // 状态。左端点。len = r - l + 1
            for (int l = 1; l <= n - len + 1; ++l) {
                int r = len + l - 1;
                // 决策 找p
                for (int p = l; p <= r; ++p) {
                    f[l][r] = max(f[l][r], f[l][p - 1] + f[p + 1][r] + nums[p] * nums[l - 1] * nums[r + 1]);
                }
            }
        }
        return f[1][n];
    }
};


/*
dfs + 记忆化搜索
先下探子问题，回溯时计算本层逻辑
*/

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        //
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        this->nums = nums;

        // 初始化-1，表示没有遍历过
        f = vector<vector<int> >(n + 2, vector<int>(n + 2, -1));

        // 0, [1,n], n+1
        return calc(1, n);
    }

   private:
    vector<int> nums;
    vector<vector<int> > f;

    // 递归的参数就是状态
    int calc(int l, int r) {
        // 递归边界
        if (l > r)
            return 0;
        // 记忆化
        if (f[l][r] != -1)
            return f[l][r];
        // 决策，找p
        for (int p = l; p <= r; ++p)
            f[l][r] = max(f[l][r], calc(l, p - 1) + calc(p + 1, r) + nums[p] * nums[l - 1] * nums[r + 1]);

        return f[l][r];
    }
};
