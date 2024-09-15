#include <vector>
using namespace std;

/*
53. 最大子数组和
https://leetcode-cn.com/problems/maximum-subarray/

思路：
max(s[r]-s[l-1]) = s[r] - min(s[j]) (r>j)
--> 固定r，计算 min(s[j])，就是前缀最小值问题
--> 前缀和+前缀最小值
*/

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + nums[i - 1];

        // =min{s[j]}, [0,j]的最小前缀和
        vector<int> preMin(n + 1);
        preMin[0] = s[0];
        for (int i = 1; i <= n; ++i)
            preMin[i] = min(preMin[i - 1], s[i]);

        int ans = -999999;
        for (int r = 1; r <= n; ++r)
            ans = max(ans, s[r] - preMin[r - 1]);

        return ans;
    }
};