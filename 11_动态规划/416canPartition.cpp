#include <vector>
using namespace std;

/*
416. 分割等和子集
https://leetcode-cn.com/problems/partition-equal-subset-sum/

子集问题，O(2^n)
选一个子集，元素总和 = sum/2
每个数字作为物品，体积能不能达到sum/2。没有价值最优化 --> 改为 true/false 可行性问题

状态 f[i][j]表示，从前i个数中选出一些数，总和是j，是否可行
状态转移: 
    不选: f[i][j] = f[i-1][j]
    选:   f[i][j] = f[i-1][j-nums[i]]
    两个只要一个可行，就可行。所以，f[i][j] = f[i-1][j-nums[i]] || f[i-1][j]
    由于只是 [i-1] 往 [i] 转移，所以可以省掉一个维度空间
*/

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        int sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<int> f(target + 1, false);
        f[0] = true; // 空背包
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                f[j] |= f[j - nums[i]];
            }
        }
        return f[target];
    }
};