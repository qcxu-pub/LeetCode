#include <vector>
using namespace std;

/*
剑指 Offer 51. 数组中的逆序对
https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

思路跟493完全一致
*/

class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }

   private:
    int ans;

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        calc(nums, left, mid, right);
        merge(nums, left, mid, right);
    }

    void calc(vector<int>& nums, int left, int mid, int right) {
        int j = mid;
        for (int i = left; i <= mid; ++i) {
            while (j < right && nums[i] > nums[j + 1])
                ++j;
            ans += (j - mid);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1;
        int n = right - left + 1;
        vector<int> temp(n, 0);
        for (int k = 0; k < n; ++k) {
            if (j > right || (i <= mid && nums[i] <= nums[j])) {
                temp[k] = nums[i];
                ++i;
            } else {
                temp[k] = nums[j];
                ++j;
            }
        }
        // copy回原数组
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i - left];
        }
    }
};