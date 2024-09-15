#include <vector>
using namespace std;

/*
78. 子集
https://leetcode-cn.com/problems/subsets/

例如：[1,2,3]: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
                        problem
           i=0不选                    i=0选
             {}                        {1}
    i=1不选        i=1选       i=1不选        i=1选
      {}           {2}          {1}          {1,2}
i=2不选 i=2选 i=2不选 i=2选 i=2不选 i=2选 i=2不选 i=2选
  {}    {3}   {2}    {2,3}   {1}  {1,3}  {1,2}  {1,2,3}

nums, i 这两个是参数。i往下传；nums全局共享，注意还原现场，不然会影响到同级别的分支
*/

class Solution {
   public:
    vector<vector<int> > subsets(vector<int> nums) {
        n = nums.size();
        recur(0, nums);
        return ans;
    }

   private:
    int n;
    vector<int> chosen;
    vector<vector<int> > ans;

    void recur(int i, vector<int> nums) {
        // 递归边界
        if (i == n) {
            ans.push_back(chosen);
            return;
        }

        // 本层要干的事情: 要不要选nums[i]
        // 1.不选
        recur(i + 1, nums);

        // 2.选
        chosen.push_back(nums[i]);
        recur(i + 1, nums);
        chosen.pop_back();  // 还原现场
    }
};