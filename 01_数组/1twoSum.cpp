#include <algorithm>
#include <vector>
using namespace std;

/*
1. 两数之和
https://leetcode-cn.com/problems/two-sum/

双指针扫描只针对有序数组，所以先排序
但排完序下标就变了，但要返回原始下标 --> 把下标跟着一起排就行了
双指针的代码复用167题
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > pairs;
        for (int i = 0; i < nums.size(); ++i)
            pairs.push_back({nums[i], i});

        sort(pairs.begin(), pairs.end());

        int j = pairs.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            while (i < j && pairs[i].first + pairs[j].first > target)
                --j;
            if (i < j && pairs[i].first + pairs[j].first == target)
                return {pairs[i].second, pairs[j].second};
        }
        return {};
    }
};