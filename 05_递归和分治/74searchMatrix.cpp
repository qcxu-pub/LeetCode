#include <vector>
using namespace std;

/*
74. 搜索二维矩阵
https://leetcode-cn.com/problems/search-a-2d-matrix/

每行的第一个整数大于前一行的最后一个整数。
所以，如果每行最后一个元素都比target小，直接下一行。找到第一个比行尾元素比target大的那行

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
            // 找到第一个行尾元素值 >=target 的那行
            while (i + 1 < m && matrix[i][n - 1] < target)
                ++i;
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                --j;
            else
                break;
        }
        return false;
    }
};