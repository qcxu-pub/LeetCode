#include <vector>
using namespace std;

/*
240. 搜索二维矩阵 II
https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

搜索路径：往中间/下面的方向走。从右上角开始找
如果 num>target，就取左边这一列，值变小；如果 num<target，就取下面一行，值变大
*/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() <= 0)
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};