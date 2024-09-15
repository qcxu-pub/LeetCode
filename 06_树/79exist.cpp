#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
79. 单词搜索
https://leetcode-cn.com/problems/word-search/

212题简化版
*/

struct Node {
    int count;
    unordered_map<char, Node*> child;
    Node() : count(0) {}
};

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        // 1.建立Trie
        this->root = new Node();  // 保护结点
        insert(word);

        // 2.DFS：之后是按照四个方向走，但第一步是枚举所有起点。这个单独做
        this->board = board;
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = true;
                dfs(i, j, root);
                visited[i][j] = false;
            }
        }
        return !ans.empty();
    }

   private:
    Node* root;
    void insert(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (curr->child.find(ch) == curr->child.end()) {
                Node* node = new Node();
                curr->child[ch] = node;
            }
            curr = curr->child[ch];
        }
        curr->count++;
    }

    vector<vector<char>> board;
    int m, n;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    vector<vector<bool>> visited;
    unordered_set<string> ans;
    string str;

    void dfs(int x, int y, Node* curr) {
        char ch = board[x][y];

        if (curr->child.find(ch) == curr->child.end())
            return;
        Node* next = curr->child[ch];  // 不能直接更新curr，不然还原不了现场了

        str.push_back(ch);
        if (next->count > 0)
            ans.insert(str);

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            dfs(nx, ny, next);
            // 还原现场
            visited[nx][ny] = false;
        }
        // 还原现场
        str.pop_back();
    }
};