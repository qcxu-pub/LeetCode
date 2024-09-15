#include <vector>
#include <algorithm>
using namespace std;

/*
31. 下一个排列
https://leetcode.cn/problems/next-permutation/

[1,2,3] -> [1,3,2] -> [2,1,3] -> [2,3,1] -> [3,1,2] -> [3,2,1] -> [1,2,3]
就是找比前一个大的数字

1.从后往前找idx，[idx,end]为递减序列
2.在[idx,end]里，找比idx-1大一点数，跟idx-1交换 --> 更高位的数字比原来的大了一些
3.对[idx,end]升序排序 --> 确定高位数字的情况下，整个数字是最小的
*/

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 1;
        while (idx >= 1) {
            if (nums[idx] <= nums[idx - 1])
                --idx;
            else
                break;
        }
        if (idx == 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int k = nums.size() - 1;
        int ich = -1;
        while (k >= idx) {
            if (nums[idx - 1] < nums[k]) {
                ich = k;
                break;
            }
            --k;
        }

        swap(nums, idx - 1, ich);
        sort(nums.begin() + idx, nums.end());
        return;
    }

   private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};