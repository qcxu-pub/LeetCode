#include <vector>
using namespace std;

/*
304. 二维区域和检索 - 矩阵不可变
https://leetcode-cn.com/problems/range-sum-query-2d-immutable/

*/

class NumMatrix {
   public:
    vector<vector<int> > sum;
    NumMatrix(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        sum.resize(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // matrix 下表从 0 开始，所以-1。如果也是从1开始，那么是matrix[i][j]
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 转化，全部从1开始
        row1++;
        row2++;
        col1++;
        col2++;
        return sum[row2][col2] - sum[row2][col1 - 1] - sum[row1 - 1][col2] + sum[row1 - 1][col1 - 1];
    }
};