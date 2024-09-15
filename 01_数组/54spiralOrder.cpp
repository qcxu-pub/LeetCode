#include <vector>
using namespace std;

/*
54. 螺旋矩阵
https://leetcode.cn/problems/spiral-matrix/

*/

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        visited = vector<vector<int>>(m, vector<int>(n, false));
        vector<int> ans;
        int dx[4] = {0, 1, 0, -1};  //右下左上
        int dy[4] = {1, 0, -1, 0};
        int k = 0;
        int i = 0, j = -1;
        for (int totnum = 0; totnum < m * n; ++totnum) {
            // 本层逻辑
            i += dx[k];
            j += dy[k];
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;

            // 下一次方向
            if (!isValid(i + dx[k], j + dy[k]) || isVisited(i + dx[k], j + dy[k]))
                k = (k + 1) % 4;
        }
        return ans;
    }

   private:
    int m, n;
    vector<vector<int>> visited;
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool isVisited(int x, int y) {
        return visited[x][y];
    }
};