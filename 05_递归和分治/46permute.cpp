#include <vector>
using namespace std;

/*
46. 全排列
https://leetcode-cn.com/problems/permutations/

input: nums = [1,2,3]
output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

一共有n!种方案

思路：从还没有被选过的里面选一个放在这里，所以要一个共享的bool数组，表示选没选过
*/

class Solution {
   public:
    vector<vector<int> > permute(vector<int>& nums) {
        n = nums.size();
        used.resize(n, false);  // used = vector<bool>(n, false);
        recur(0, nums);
        return ans;
    }

   private:
    int n;
    vector<bool> used;
    vector<int> chosen;
    vector<vector<int> > ans;

    void recur(int level, vector<int>& nums) {
        // 递归边界
        if (level == n) {
            ans.push_back(chosen);
            return;
        }

        // 本层要干的事情：选一个没有选择过的数塞在当前位置
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                chosen.push_back(nums[i]);
                used[i] = true;
                recur(level + 1, nums);
                // 还原现场
                used[i] = false;
                chosen.pop_back();
            }
        }
    }
};