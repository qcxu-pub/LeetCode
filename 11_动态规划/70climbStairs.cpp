#include <vector>
using namespace std;

/*
70. 爬楼梯
https://leetcode-cn.com/problems/climbing-stairs/

状态: f[i] = 走到第 i 阶台阶的方案数
递推关系: f[i] = f[i-1] + f[i-2]
*/

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 2; i <= n; ++i) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans[n];
    }
};