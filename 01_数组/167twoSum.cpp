#include <vector>
using namespace std;

/*
167. 两数之和 II - 输入有序数组
https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

两头向中间移动的双指针问题
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); ++i) {
            while (i < j && numbers[i] + numbers[j] > target)
                --j;
            if (i < j && numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }
        return {};
    }
};