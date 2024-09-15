#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
36. 有效的数独
https://leetcode-cn.com/problems/valid-sudoku/

经37题验证，数组更快些。。
unordered_set<char> row[9]
unordered_set<char> col[9]
unordered_set<char> box[9]
*/

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> used_block;
        unordered_map<int, unordered_set<char>> used_row;  // {0:{1,2,3}}
        unordered_map<int, unordered_set<char>> used_col;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;

                int idx = hash(int(i / 3), int(j / 3));
                auto ans_row = used_row[i].find(ch);
                auto ans_col = used_col[j].find(ch);
                auto ans_block = used_block[idx].find(ch);

                if (ans_row != used_row[i].end() || ans_col != used_col[i].end() || ans_block != used_block[idx].end())
                    return false;

                used_row[i].insert(ch);
                used_col[j].insert(ch);
                used_block[idx].insert(ch);
            }
        }
        return true;
    }

   private:
    // 二维转一维 
    int hash(int x, int y) {
        return 3 * x + y;
    }
};