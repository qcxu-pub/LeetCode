#include <unordered_map>
#include <vector>
using namespace std;

/*
560. 和为 K 的子数组
https://leetcode-cn.com/problems/subarray-sum-equals-k/

思路：字段和 = 常数k
sum(r) - sum(l-1) = k
--> 前缀和 + 两数之差
*/

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + nums[i - 1];

        int ans = 0;
        unordered_map<int, int> hashtable;
        for (int i = 0; i < sum.size(); ++i) {
            int s = sum[i];

            auto it_left = hashtable.find(s - k);
            if (it_left != hashtable.end())
                ans += it_left->second;

            auto it_right = hashtable.find(s);
            if (it_right != hashtable.end())
                hashtable[s] += 1;
            else
                hashtable[s] = 1;
        }
        return ans;
    }
};