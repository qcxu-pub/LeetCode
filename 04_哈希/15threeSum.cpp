#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

#include <iostream>

/*
15. 三数之和
https://leetcode-cn.com/problems/3sum/

思路：hashmap，可以c=target-(a+b)，可以去掉一重循环。
另外一种思路是用 sort&find
*/

class Solution {
   public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() < 3)
            return ans;

        sort(nums.begin(), nums.end());  // 为了方便去掉重复的答案
        for (int i = 0; i < nums.size() - 2; ++i) {
            // duplicate
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;

            unordered_set<int> sum;
            for (int j = i + 1; j < nums.size(); ++j) {
                //...,-2,1,1,1; ...,-2,-1,3,3
                if (j >= i + 3 && nums[j] == nums[j - 2])
                    continue;

                auto iter = sum.find(-nums[j]);
                if (iter != sum.end()) {
                    ans.push_back({nums[i], -nums[j] - nums[i], nums[j]});
                    sum.erase(iter);  //
                } else {
                    sum.insert(nums[i] + nums[j]);
                }
            }
        }
        return ans;
    }
};


/*
分模块写 sort&find
可以对比数组中的写法
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            vector<vector<int>> jks = twoSum(nums, i + 1, -nums[i]);
            for (vector<int>& jk : jks) {
                ans.push_back({nums[i], jk[0], jk[1]});
            }
        }
        return ans;
    }

   private:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ans;
        unordered_set<int> h;
        for (int i = start; i < nums.size(); ++i) {
            // twoSum, i-2
            if (i > start + 1 && nums[i] == nums[i - 2])
                continue;

            auto iter = h.find(target - nums[i]);
            if (iter != h.end()) {
                ans.push_back({nums[i], target - nums[i]});
                h.erase(iter);
            } else {
                h.insert(nums[i]);
            }
        }
        return ans;
    }
};