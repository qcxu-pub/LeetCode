#include <vector>
using namespace std;

/*
152. 乘积最大子数组
https://leetcode-cn.com/problems/maximum-product-subarray/

跟53题对比，f[i]=max(f[i-1]*nums[i], nums[i]) 不对了。因为有负数。
选的代表要有推导关系。之前max之后也是max，之前是min之后也是min，这样才行。

负负得正，所以这里不对。说明代表不够多。选一个不行，就选两个
fmax[i] = max(fmax[i-1]*nums[i], fmin[i-1]*nums[i], nums[i])
fmin[i] = min(fmax[i-1]*nums[i], fmin[i-1]*nums[i], nums[i])
*/

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> fmax(n, 0);
        vector<int> fmin(n, 0);
        fmax[0] = nums[0];
        fmin[0] = nums[0];
        // 以当前为结尾的乘积最大子段
        for (int i = 1; i < n; ++i) {
            fmax[i] = max(nums[i], max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]));
            fmin[i] = min(nums[i], min(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]));
        }
        // 全局乘积最大子段
        int ans = nums[0];
        for (int i = 0; i < n; ++i) {
            ans = max(ans, fmax[i]);
        }
        return ans;
    }
};