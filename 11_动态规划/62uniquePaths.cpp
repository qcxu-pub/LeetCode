#include <vector>
using namespace std;

/*
62. 不同路径
https://leetcode-cn.com/problems/unique-paths/

状态: f[i,j]表示到达(i,j)这个位置的路径数

状态转移1: 从哪里来
f[i,j] = f[i-1,j] + f[i,j-1]
   x
x  ?

状态转移2: 到哪里去
f[i+1,j] += f[i,j]
f[i,j+1] += f[i,j]
x  x
x

目标: f[m-1][n-1]

*/

/*从哪里来*/
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 边界初始化
                if (i == 0 && j == 0) {
                    f[i][j] = 1;
                    continue;
                }
                int up = i - 1 >= 0 ? f[i - 1][j] : 0;
                int left = j - 1 >= 0 ? f[i][j - 1] : 0;
                f[i][j] = up + left;
            }
        }
        return f[m - 1][n - 1];
    }
};

/*到哪里去*/
class Solution {
   public:
    int uniquePaths(int m, int n) {
        // 怕+1越界了。。就多开了一个
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i + 1][j] += f[i][j];
                f[i][j + 1] += f[i][j];
            }
        }

        return f[m - 1][n - 1];
    }
};