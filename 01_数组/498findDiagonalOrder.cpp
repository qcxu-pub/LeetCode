#include <vector>
using namespace std;

/*
498. 对角线遍历
https://leetcode.cn/problems/diagonal-traverse/

*/

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int> >& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<int> ans;
        k = 0;
        int i = 0, j = 0;
        while (isValid(i, j)) {
            // 本层逻辑
            ans.push_back(mat[i][j]);
            // 下一次方向
            vector<int> nextStart = getNext(i, j);
            i = nextStart[0];
            j = nextStart[1];
        }
        return ans;
    }

   private:
    int m, n;
    int k;
    // 右上: [1,1]->[0,2]
    // 左下: [1,1]->[2,0]
    int dx[2] = {-1, 1};  //右上,左下
    int dy[2] = {1, -1};

    vector<int> getNext(int x, int y) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        // 下一步不超界限
        if (isValid(nx, ny))
            return {nx, ny};

        // 下一步超界了
        k = (k + 1) % 2;
        // 右上角
        if (x == 0 && y == n - 1)
            return {x + 1, y};
        // 左下角
        if (x == m - 1 && y == 0)
            return {x, y + 1};
        // 上下边碰壁
        if (x == 0 || x == m - 1)
            return {x, y + 1};
        // 左右边碰壁
        else if (y == 0 || y == n - 1)
            return {x + 1, y};
        return {-1, -1};
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};