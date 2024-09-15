#include <unordered_map>
#include <vector>
using namespace std;

/*
1. 两数之和
https://leetcode-cn.com/problems/two-sum/

思路：返回index，所以用hash map，key=数值，value=下标
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (h.find(target - nums[i]) != h.end())
                return {h[target - nums[i]], i};
            h[nums[i]] = i;
        }
        return {};
    }

   private:
    unordered_map<int, int> h;
};