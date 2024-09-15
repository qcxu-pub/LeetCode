#include <vector>
using namespace std;

/*
200. 岛屿数量
https://leetcode-cn.com/problems/number-of-islands/

深搜和广搜那章用了bfs。这里用并查集做
思路跟547一样
有多少岛屿，就是有多少根是'1'
*/

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // 初始化根 fa
        makeSet();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0')
                    continue;

                for (int k = 0; k < 2; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                        continue;

                    // (i,j),(ni,nj)都是'1'
                    if (grid[ni][nj] == '1')
                        unionSet(num(i, j), num(ni, nj));
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = num(i, j);
                if (grid[i][j] == '1' && fa[x] == x)
                    ans += 1;
            }
        }
        return ans;
    }

   private:
    int m, n;
    vector<int> fa;
    const int dx[2] = {0, 1};  //就整了两个方向数组，向下&向右
    const int dy[2] = {1, 0};

    // 二维转一维
    int num(int i, int j) {
        return i * n + j;  //
    }

    void makeSet() {
        fa = vector<int>(m * n, 0);
        for (int x = 0; x < m * n; ++x)
            fa[x] = x;
    }

    // 找x的总根
    int find(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    // 合并
    void unionSet(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            fa[fx] = fy;
        }
    }
};