#include <vector>
using namespace std;

/*
77. 组合
https://leetcode-cn.com/problems/combinations/

input: n = 4, k = 2, 返回范围 [1, n] 中所有可能的 k 个数的组合
output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

思路：
相比78子集就多了1个参数k，限制了一下选择的数量。

*/

class Solution {
   public:
    vector<vector<int> > combine(int n, int k) {
        this->n = n;
        this->k = k;
        recur(1);
        return ans;
    }

   private:
    int n, k;
    vector<int> chosen;
    vector<vector<int> > ans;

    void recur(int i) {
        // 剪枝
        if (chosen.size() > k || chosen.size() + (n - i + 1) < k)
            return;
        // 递归边界
        if (i == n + 1) {
            ans.push_back(chosen);
            return;
        }

        // 本层要干的事情：要不要选i
        // 1. 不选
        recur(i + 1);

        // 2.选
        chosen.push_back(i);
        recur(i + 1);
        chosen.pop_back();  // 还原现场
    }
};