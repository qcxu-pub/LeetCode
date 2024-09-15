#include <vector>
using namespace std;

/*
120. 三角形最小路径和
https://leetcode-cn.com/problems/triangle/

状态: 从顶点走到当前位置(i,j)的最小路径和 f[i][j]
状态转移方程: f[i][j] = min(f[i-1][j], f[i-1][j-1]) + triangle[i][j]

x
x x
x x x

*/

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row - 1].size();
        vector<vector<int>> f(row, vector<int>(col, 0));
        // 边界
        f[0][0] = triangle[0][0];

        for (int i = 1; i < row; ++i) {
            // 边界
            f[i][0] = f[i - 1][0] + triangle[i][0];
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
            // 状态转移
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];
            }
        }

        // 全局最优解
        int ans = f[row - 1][0];
        for (int j = 0; j < col; ++j) {
            ans = min(ans, f[row - 1][j]);
        }
        return ans;
    }
};