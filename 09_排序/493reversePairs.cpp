#include <vector>
using namespace std;

/*
493. 翻转对
https://leetcode-cn.com/problems/reverse-pairs/

在一个数组找那个统计特定大小关系的pair数量。同类型的还有逆序对。
当一个题目既有下标位置关系，又有值的关系的时候，为了让条件少一个，可以用归并排序，然后双指针扫描统计
calc([1,3,2, 3,1]) = calc([1,3,2]) + calc([3,1]) +
左右跨越的，左边取i右边取j，统计nums[i]>2*nums[j]的数量
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

    void calc(vector<int>& arr, int left, int mid, int right) {
        // [left, mid], [mid+1, right]
        int j = mid;
        for (int i = left; i <= mid; ++i) {
            while (j < right && arr[i] > 2l * arr[j + 1])
                ++j;
            ans += (j - mid);
        }
    }

    void merge(vector<int>& a, int left, int mid, int right) {
        int n = right - left + 1;
        vector<int> temp(n, 0);
        int i = left, j = mid + 1;
        for (int k = 0; k < n; ++k) {
            if (j > right || (i <= mid && a[i] <= a[j])) {
                temp[k] = a[i];
                ++i;
            } else {
                temp[k] = a[j];
                ++j;
            }
        }
        // copy回原数组
        for (int k = 0; k < n; ++k) {
            a[left + k] = temp[k];
        }
    }
};