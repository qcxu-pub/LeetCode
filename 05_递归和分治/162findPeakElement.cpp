#include <vector>
using namespace std;

/*
162. 寻找峰值
https://leetcode-cn.com/problems/find-peak-element/

如果有多个峰值的话，找到的可能是局部最优解
*/

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int lmid = (left + right) / 2;
            int rmid = lmid + 1;
            if (nums[lmid] <= nums[rmid]) {
                left = lmid + 1;
            } else {
                right = rmid - 1;
            }
        }
        return right;
    }
};