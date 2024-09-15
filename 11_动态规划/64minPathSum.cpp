#include <vector>
using namespace std;

/*
64. 最小路径和
https://leetcode-cn.com/problems/minimum-path-sum/

状态: f[i,j]表示从左上角到(i,j)这个格子的最小路径和
状态转移:
1.从哪里来
  x
x ?
f[i,j] = min(f[i-1,j], f[i,j-1]) + grid[i,j]

2.到哪里去
x x
x
f[i+1,j] = min(f[i+1,j], f[i,j]+grid[i+1,j])
f[i,j+1] = min(f[i,j+1], f[i,j]+grid[i,j+1])

目标: f[m-1][n-1]
*/


/*从哪里来*/
class Solution {
   public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 1e9 因为要算最小值
        vector<vector<int> > f(m, vector<int>(n, 1e9));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 边界
                if (i == 0 && j == 0) {
                    f[i][j] = grid[i][j];
                    continue;
                }
                int up = i - 1 >= 0 ? f[i - 1][j] : 1e9;
                int left = j - 1 >= 0 ? f[i][j - 1] : 1e9;
                f[i][j] = min(up, left) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};


/*到哪里去*/
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 后面+1会越界了
        grid.insert(grid.end(), vector<int>(n, 0));
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 1e9));
        f[0][0] = grid[0][0];

        for (int i = 0; i < m; ++i) {
            grid[i].insert(grid[i].end(), 0);
            for (int j = 0; j < n; ++j) {
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + grid[i + 1][j]);
                f[i][j + 1] = min(f[i][j + 1], f[i][j] + grid[i][j + 1]);
            }
        }
        return f[m - 1][n - 1];
    }
};