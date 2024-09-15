#include <vector>
using namespace std;

/*
221. 最大正方形
https://leetcode-cn.com/problems/maximal-square/

状态: f[i,j]表示从左上角到(i,j)这个结点组成的最大正方形边长
边界: i==0 || j==0 时, f[i,j] = matrix[i,j]
状态转移: 正方形边长变长的轮廓
↘
  ↘
    ↘
所以，f[i,j] = min(f[i-1,j], f[i,j-1], f[i-1,j-1]) + 1
目标: s = max{f[i,j]} ^ 2
*/

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

        int maxSide = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 0 的不算边长，直接continue掉
                if (matrix[i][j] == '0')
                    continue;

                // 边界初始化
                if (i == 0 || j == 0) {
                    f[i][j] = 1;
                    maxSide = max(maxSide, f[i][j]);
                    continue;
                }
                // 递推
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                maxSide = max(maxSide, f[i][j]);
            }
        }
        return maxSide * maxSide;
    }
};