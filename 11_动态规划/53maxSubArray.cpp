#include <vector>
using namespace std;

/*
53. 最大子数组和
https://leetcode-cn.com/problems/maximum-subarray/

之前用前缀和做过。
如果用搜索做，就是选或者不选，O(2^n)
用动规做。思路跟300LIS有点像
因为这里结尾参与了判定条件，所以状态中要包含结尾

状态: f[i] 表示以 i 为结尾的最大子段和
递推关系: f[i] = max(f[i-1] + nums[i], nums[i])
边界: f[0] = nums[0]
目标: max(f[i]), 其中 0 <= i < n

这样就可以过渡到贪心: 前面的字段和如果是正贡献就要，否则就不要

*/

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0);
        f[0] = nums[0];
        // 以当前为结尾的最大子段和
        for (int i = 1; i < nums.size(); ++i) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        }
        int ans = nums[0];
        // 全局的最大子段和
        for (int i = 0; i < nums.size(); ++i) {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};