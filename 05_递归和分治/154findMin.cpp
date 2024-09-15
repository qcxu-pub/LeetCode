#include <vector>
using namespace std;

/*
154. 寻找旋转排序数组中的最小值 II
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

相比153题，多了重复元素
这样会使 v[mid] <= v[right] 这条语句直接跳过最小值点，取更左的部分
所以想法是，过滤跟target一样的元素。target还是保留在尾部。这样就跟153题一样了

[0,1,1]，nums[mid]=1时，应该走right=mid，所以是<=
[3,3,1,3]，nums[mid]=3时，应该left=mid+1，因为3就是结尾取值。所以要先过滤跟结尾一样的数
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int target = nums[nums.size() - 1];
        vector<int> v;
        for (int num : nums) {
            if (num != target) {
                v.push_back(num);
            }
        }
        v.push_back(target);

        int left = 0;
        int right = v.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            // 满足不等式条件
            if (v[mid] <= v[right])
                right = mid;
            else
                left = mid + 1;
        }
        return v[right];
    }
};