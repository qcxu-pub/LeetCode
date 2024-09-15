#include <vector>
#include <string>
using namespace std;

/*
79. 单词搜索
https://leetcode.cn/problems/word-search/

也可以用 Trie树 做，见 06_树 79/212

这里就考虑，当前位置要不要走。取决于四个方向&后面字符串的匹配结果
*/

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        this->board = board;
        this->word = word;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(0, i, j))
                    return true;
            }
        }
        return false;
    }

   private:
    int m, n;
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;

    // 当前位置要不要走
    bool dfs(int idx, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n)
            return false;
        if (visited[x][y])
            return false;
        if (word[idx] != board[x][y])
            return false;
        if (idx == word.length() - 1)
            return true;
        // 本层逻辑
        visited[x][y] = true;
        bool ans = dfs(idx + 1, x, y - 1) || dfs(idx + 1, x, y + 1) ||
                   dfs(idx + 1, x - 1, y) || dfs(idx + 1, x + 1, y);
        visited[x][y] = false;
        return ans;
    }
};