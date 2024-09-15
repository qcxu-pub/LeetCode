#include <vector>
using namespace std;

/*
33. 搜索旋转排序数组
https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

先找到开始的位置(同153)，然后再二分找target
*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[n - 1])
                right = mid;
            else
                left = mid + 1;
        }

        // cout << "index=" << right << endl;
        // cout << "target=" << target << ",nums[0]=" << nums[0] << ",nums[n-1]=" << nums[n-1] << ",nums[right]=" << nums[right] << endl;

        // [0,right][right,n-1], [4,5,6,7][0,1,2]
        int start = -1, end = -1;
        if (target == nums[right])
            return right;
        else if (right == 0) {
            if (target >= nums[0] && target <= nums[n - 1]) {
                start = 0;
                end = n - 1;
            }
        } else if (right == n - 1) {
            if (target >= nums[0] && target <= nums[right - 1]) {
                start = 0;
                end = right - 1;
            }
        } else if (right >= 1 && target >= nums[0] && target <= nums[right - 1]) {
            start = 0;
            end = right;
        } else if (target >= nums[right] && target <= nums[n - 1]) {
            start = right;
            end = n - 1;
        }
        // cout << "start=" << start << ",end=" << end << endl;
        if (start == -1 || end == -1)
            return -1;

        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }

        return nums[end] == target ? end : -1;
    }
};