#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
47. 全排列 II
https://leetcode-cn.com/problems/permutations-ii/

input: nums = [1,1,2]
output: 按任意顺序 返回所有不重复的全排列
[[1,1,2],
 [1,2,1],
 [2,1,1]]

相比46的全排列，多一个去重
*/

class Solution {
   public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        this->n = nums.size();
        used = vector<bool>(n, false);
        recur(0, nums);
        return ans;
    }

   private:
    int n;
    unordered_set<string> s;
    vector<bool> used;
    vector<vector<int> > ans;
    vector<int> chosen;

    void recur(int level, vector<int>& nums) {
        // 递归边界
        if (level == n && s.find(getHash(chosen)) == s.end()) {
            ans.push_back(chosen);
            s.insert(getHash(chosen));
            return;
        } else if (level == n) {
            return;
        }

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

    string getHash(vector<int>& chosen) {
        string s = "";
        for (int c : chosen) {
            s += to_string(c);
        }
        return s;
    }
};