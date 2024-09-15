#include <algorithm>
#include <vector>
using namespace std;

/*
215. 数组中的第K个最大元素
https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

在乱序数组中找第k大
*/

/*
默认快排，从小到大排序，要第k大，所以取倒数第k个
时间复杂度：O(nlogn)
*/
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


/*
手动快排。找个中轴，左边小，右边大。递归。
要的是第k大，所以只要递归一边就好了
时间复杂度：n + n/2 + n/4 + n/8 + ... < 2n = O(n)
*/
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
    }

   private:
    // 在 [l,r] 之间找第index个大小
    int quickSort(vector<int>& arr, int l, int r, int index) {
        if (l >= r)
            return arr[l];
        int pivot = partition(arr, l, r);
        if (index <= pivot)
            return quickSort(arr, l, pivot, index);
        else
            return quickSort(arr, pivot + 1, r, index);           
    }

    int partition(vector<int>& a, int l, int r) {
        int pivot = l + rand() % (r - l + 1);
        int pivotVal = a[pivot];
        while (l <= r) {
            while (a[l] < pivotVal)
                ++l;
            while (a[r] > pivotVal)
                --r;
            if (l == r)
                break;
            if (l < r) {
                int temp = a[l];
                a[l] = a[r];
                a[r] = temp;
                ++l;
                --r;
            }
        }
        return r;
    }
};