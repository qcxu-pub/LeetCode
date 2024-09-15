#include <vector>
using namespace std;

/*
279. 完全平方数
https://leetcode-cn.com/problems/perfect-squares/

完全背包问题
完全平方数=物品
体积=n
价值=1

状态f[i,j]: 前i个完全平方数，凑成体积j 的最少数量
状态转移:
还没有取第i个数: f[i,j] = f[i-1,j]
取第i个数: f[i,j] = f[i,j-i^2] + 1
初值: f[i,0] = 0
目标: min{f[i,n]}, 0<=i<n
*/

class Solution {
   public:
    int numSquares(int n) {
        vector<int> f(n + 1, 1e9);
        f[0] = 0;

        // for物品
        for (int i = 1; i <= n; ++i) {
            // for体积
            for (int j = i * i; j <= n; ++j) {
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }

        return f[n];
    }
};