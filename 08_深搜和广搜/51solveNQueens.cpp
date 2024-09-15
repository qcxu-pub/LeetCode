#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#include <iostream>

/*
51. N 皇后
https://leetcode-cn.com/problems/n-queens/

思路：
一行一行来，主要关心每一行放哪儿。这样只要用一维数组表示每一行的列号就好了，且列号不会重复（因为同一列的会互相攻击），[1,2,3,...,n]
这样问题就转化为一个排列问题了。

另外对角线也会相互攻击
\ (1,1)(2,2), (0,1)(1,2) --> i-j 相等
/ (1,0)(0,1), (2,1)(1,2) --> i+j 相等

用 usedPlus, usedMinus 做剪枝
*/

class Solution {
   public:
    vector<vector<string> > solveNQueens(int n) {
        this->n = n;
        used = vector<bool>(n, false);
        dfs(0);

        // for (vector<int>& a: ans) {
        //     for (int n : a)
        //         cout << n << ",";
        //     cout << endl;
        // }

        // 转化为题目要的输出pattern
        vector<vector<string> > result;
        for (vector<int>& p : ans) {
            vector<string> pattern(n, string(n, '.'));
            for (int row = 0; row < n; ++row) {
                int col = p[row];
                pattern[row][col] = 'Q';
            }
            result.push_back(pattern);
        }
        return result;
    }

   private:
    int n;
    vector<int> cols;
    vector<vector<int> > ans;
    vector<bool> used;
    unordered_map<int, bool> usedPlus;
    unordered_map<int, bool> usedMinus;

    void dfs(int row) {
        // 递归边界, level
        if (row == n) {
            ans.push_back(cols);
            return;
        }

        // 本层要干的事情：当前行row棋子落在哪一列col
        for (int col = 0; col < n; col++) {
            if (!used[col] && !usedPlus[row + col] && !usedMinus[row - col]) {
                // 更新状态
                used[col] = true;
                cols.push_back(col);
                usedPlus[row + col] = true;
                usedMinus[row - col] = true;

                // 递归求下一行
                dfs(row + 1);

                // 还原现场
                usedMinus[row - col] = false;
                usedPlus[row + col] = false;
                cols.pop_back();
                used[col] = false;
            }
        }
    }
};


/*
52. N皇后 II
https://leetcode-cn.com/problems/n-queens-ii/

只是返回值不一样
*/

class Solution {
   public:
    int totalNQueens(int n) {
        this->n = n;
        used = vector<bool>(n, false);
        dfs(0);

        // for (vector<int>& a: ans) {
        //     for (int n : a)
        //         cout << n << ",";
        //     cout << endl;
        // }

        return ans.size();
    }

   private:
    int n;
    vector<int> cols;
    vector<vector<int> > ans;
    vector<bool> used;
    unordered_map<int, bool> usedPlus;
    unordered_map<int, bool> usedMinus;

    void dfs(int row) {
        // 递归边界, level
        if (row == n) {
            ans.push_back(cols);
            return;
        }

        // 本层要干的事情：当前行row棋子落在哪一列col
        for (int col = 0; col < n; col++) {
            if (!used[col] && !usedPlus[row + col] && !usedMinus[row - col]) {
                // 更新状态
                used[col] = true;
                cols.push_back(col);
                usedPlus[row + col] = true;
                usedMinus[row - col] = true;

                // 递归求下一行
                dfs(row + 1);

                // 还原现场
                usedMinus[row - col] = false;
                usedPlus[row + col] = false;
                cols.pop_back();
                used[col] = false;
            }
        }
    }
};

