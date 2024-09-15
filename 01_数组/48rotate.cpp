#include <vector>
using namespace std;

/*
48. 旋转图像
https://leetcode.cn/problems/rotate-image/

*/

/*
上下颠倒 + 转置 = 顺时针旋转90度
1 2 3      7 8 9     7 4 1
4 5 6 -->  4 5 6 --> 8 5 2
7 8 9      1 2 3     9 6 3
*/

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix, i, j);
            }
        }
    }

   private:
    void swap(vector<vector<int>>& matrix, int i, int j) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
    }
};

/*
暴力旋转

[0,0] [0,1] [0,2]       [0,2] [1,2] [2,2]
[1,0] [1,1] [1,2]  ---> [0,1] [1,1] [2,1]
[2,0] [2,1] [2,2]       [0,0] [1,0] [2,0]

[1,0] <- [0,1] <- [1,2] <- [2,1] 这四个点相互旋转
[i,j] <- [j,n-1-i] <- [n-1-i,n-1-j] <- [n-1-j,i]
看跟靠边的距离相等的关系，推导出来的

注意i,j的取值范围
*/

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
    }
};