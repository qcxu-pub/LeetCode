#include <vector>
using namespace std;

/*
34. 在排序数组中查找元素的第一个和最后一个位置
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

input: 升序数组 nums = [5,7,7,8,8,10], target = 8
output: [3,4]

开始位置：>=target 的最小index
结束位置：<=target 的最大index
*/

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int left = 0, right = nums.size();  // 找不到时 right=n
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                // 要第一个最小index，所以是要左边
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans.push_back(right);

        left = -1, right = nums.size() - 1;  // 找不到时 left=-1
        while (left < right) {
            int mid = (left + right + 1) / 2;  // 要+1，不然mid=left，后面又left=mid，陷入死循环
            if (nums[mid] <= target) {
                // 要最后一个最大index，所以是要右边
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ans.push_back(right);

        if (ans[0] > ans[1])
            return {-1, -1};
        else
            return ans;
    }
};