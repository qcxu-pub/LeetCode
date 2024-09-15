#include <vector>
using namespace std;

/*
59. 螺旋矩阵 II
https://leetcode.cn/problems/spiral-matrix-ii/

*/

class Solution {
   public:
    vector<vector<int> > generateMatrix(int n) {
        this->n = n;
        ans = vector<vector<int> >(n, vector<int>(n, 0));
        int dx[4] = {0, 1, 0, -1};  // 右下左上
        int dy[4] = {1, 0, -1, 0};
        int k = 0;
        int i = 0, j = -1;
        for (int totnum = 1; totnum <= n * n; ++totnum) {
            // 本层逻辑
            i += dx[k];
            j += dy[k];
            ans[i][j] = totnum;

            // 下一次方向
            if (!isValid(i + dx[k], j + dy[k]) || isVisited(i + dx[k], j + dy[k])) {
                k = (k + 1) % 4;
            }
        }
        return ans;
    }

   private:
    int n;
    vector<vector<int> > ans;

    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    bool isVisited(int x, int y) {
        return ans[x][y] > 0;
    }
};