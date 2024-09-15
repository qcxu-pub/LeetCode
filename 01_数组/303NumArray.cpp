#include <vector>
using namespace std;

/*
303. 区域和检索 - 数组不可变
https://leetcode-cn.com/problems/range-sum-query-immutable/

*/

class NumArray {
   public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + nums[i - 1];  // nums[0] 开始
    }

    int sumRange(int left, int right) {
        left++;
        right++;
        return sum[right] - sum[left - 1];
    }
};