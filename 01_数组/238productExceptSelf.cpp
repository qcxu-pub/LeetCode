#include <vector>
using namespace std;

/*
238. 除自身以外数组的乘积
https://leetcode.cn/problems/product-of-array-except-self/

要求的是除了自己的其他元素的乘积
所以，前缀累积乘积 * 后缀累积乘积 = 当前位置的答案

*/

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> suf(n, 1);

        pre[0] = nums[0];
        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] * nums[i];

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suf[i] = suf[i + 1] * nums[i];

        vector<int> ans(n, 0);
        ans[0] = suf[1];
        ans[n - 1] = pre[n - 2];
        for (int i = 1; i < n - 1; ++i)
            ans[i] = pre[i - 1] * suf[i + 1];
        return ans;
    }
};