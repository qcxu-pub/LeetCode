#include <vector>
using namespace std;

/*
153. 寻找旋转排序数组中的最小值
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

旋转升序排序数组，旋转一次: [a[0], a[1], a[2], ..., a[n-1]] -> [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 

不等式条件->0/1分段函数，用二分查找用于找分界点
每个数跟结尾比较，这样就得到了分段单调的数组
本质找的是第一个比结尾小的数，也就是第一个从0到1的位置
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            // 满足不等式条件 <也可
            if (nums[mid] <= nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[right];
    }
};