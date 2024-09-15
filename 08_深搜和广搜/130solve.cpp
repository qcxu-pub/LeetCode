#include <vector>
#include<queue>
using namespace std;

/*
130. 被围绕的区域
https://leetcode-cn.com/problems/surrounded-regions/

想法是，bfs遍历。只有跟边界的o相连的不是x，其他的都是x

后面可以用并查集做
*/

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        this->board = board;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        ans = vector<vector<char>>(m, vector<char>(n, 'X'));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    board[i][j] == 'O') {
                    bfs(i, j);
                }
            }
        }

        // 转成要的答案格式
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ans[i][j] == 'X') {
                    board[i][j] = 'X';
                }
            }
        }
    }

   private:
    int m, n;
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    vector<vector<char>> ans;

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    void bfs(int sx, int sy) {
        queue<pair<int, int>> q;
        q.push(make_pair(sx, sy));
        visited[sx][sy] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ans[x][y] = 'O';

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] == 'X')
                    continue;

                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
};