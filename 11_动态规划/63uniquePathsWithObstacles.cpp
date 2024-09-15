#include <vector>
using namespace std;

/*
63. 不同路径 II
https://leetcode-cn.com/problems/unique-paths-ii/

搜索求解。可以写个dfs(int x, int y)，是从(x,y)这个点出发，到end 的路径计数
为什么慢？因为有重复计算。start->(x,y) 的路径有很多条，(x,y)->end 的路径也有很多条
但一旦走到(x,y)之后，(x,y)->end 挑一个代表就好了，没必要重复求解
所以，状态: (x,y)

botton-up思想：
从start开始走，下一步是往右走或者往下走。这样路径计数关系就有了
状态转移: path(x,y) = path(x+1,y) + path(x,y+1)，其中(x,y)表示从(x,y)到end的路径数
如果可以往各个方向走，就变成了图的遍历，就要开个 visited 数组了
a+b b
 a
动规求解的目标: start处的累积值

倒过来的top-down思想：
(x,y)表示从start到(x,y)的路径数，那么要到达(x,y)，要么从上面来，要么从左边来
所以递推关系就变成: path(x,y) = path(x-1,y) + path(x,y-1)
   a
b a+b
动规求解的目标: end处的累积值
*/


/*
bottom-up
递归 + 记忆化搜索
*/
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        this->obstacleGrid = obstacleGrid;
        grid = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        dfs(0, 0);
        return grid[0][0];
    }

   private:
    int m, n;
    vector<vector<int>> obstacleGrid;
    vector<vector<int>> grid;

    void dfs(int x, int y) {
        // 边界条件
        if (!isValid(x, y))
            return;
        if (!isObstable(x, y) && isEnd(x, y)) {
            grid[x][y] = 1;
            return;
        }
        if (isObstable(x, y)) {
            grid[x][y] = 0;
            return;
        }
        // 记忆化，是否遍历过
        if (isValid(x + 1, y) && !isObstable(x + 1, y) && grid[x + 1][y] == 0)
            dfs(x + 1, y);
        if (isValid(x, y + 1) && !isObstable(x, y + 1) && grid[x][y + 1] == 0)
            dfs(x, y + 1);
        // 本层逻辑
        grid[x][y] = grid[x + 1][y] + grid[x][y + 1];
    }

    bool isEnd(int x, int y) {
        return x == m - 1 && y == n - 1;
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool isObstable(int x, int y) {
        return obstacleGrid[x][y] == 1;
    }
};


/*
top-down
递推
*/
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        this->obstacleGrid = obstacleGrid;
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 起点是障碍物的话，不管后面是什么样的，结果都是0
                if (i == 0 && j == 0 && !isObstable(i, j)) {
                    grid[i][j] = 1;
                    continue;
                }
                if (!isValid(i, j) || isObstable(i, j))
                    continue;
                int left = isValid(i - 1, j) && !isObstable(i - 1, j) ? grid[i - 1][j] : 0;
                int up = isValid(i, j - 1) && !isObstable(i, j - 1) ? grid[i][j - 1] : 0;
                grid[i][j] = left + up;
            }
        }
        return grid[m - 1][n - 1];
    }

   private:
    int m, n;
    vector<vector<int>> obstacleGrid;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool isObstable(int x, int y) {
        return obstacleGrid[x][y] == 1;
    }
};