#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
212. 单词搜索 II
https://leetcode-cn.com/problems/word-search-ii/

可以用纯DFS做，但每次都会重新遍历每个单词，耗时 --> 候选池单词预处理：字典树
--> 地图类搜索(DFS+方向数组) + 字典树
DFS搜索的时候，要判断走的路径是否是单词的前缀(208题)。所以要先给words建立一颗字典树
*/

struct Node {
    int count;
    unordered_map<char, Node*> child;
    Node() : count(0) {}
};

class Solution {
   public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        // 1.建立Trie
        this->root = new Node();  // 保护结点
        for (const string& word : words) {
            insert(word);
        }

        // 2.DFS：之后是按照四个方向走，但第一步是枚举所有起点。这个单独做
        this->board = board;
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool> >(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = true;
                dfs(i, j, root);
                visited[i][j] = false;
            }
        }

        return vector<string>(ans.begin(), ans.end());
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

    vector<vector<char> > board;
    int m, n;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    vector<vector<bool> > visited;
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


/*
优化：
上述解法有个极端情况：单词是100个a，12*12的网格中也都是a，这样网格搜索也能有很多很多条路径
针对这个问题，可以把已经找到的单词从words中删除，这样网格中还是只找一条
删除具体的方法是，叶子count--，在探索到底的时候；如果子节点为空，就把这个分支删掉，在回溯的时候。下次递归的时候Trie树就更小了，就会快一点
*/

class Solution2 {
   public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        // 1.建立Trie
        this->root = new Node();  // 保护结点
        for (const string& word : words) {
            insert(word);
        }

        // 2.DFS：之后是按照四个方向走，但第一步是枚举所有起点。这个单独做
        this->board = board;
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool> >(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = true;
                dfs(i, j, root);
                visited[i][j] = false;
            }
        }

        return vector<string>(ans.begin(), ans.end());
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

    vector<vector<char> > board;
    int m, n;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    vector<vector<bool> > visited;
    unordered_set<string> ans;
    string str;

    void dfs(int x, int y, Node* curr) {
        if (curr == nullptr)
            return;

        char ch = board[x][y];

        if (curr->child.find(ch) == curr->child.end())
            return;
        Node* next = curr->child[ch];  // 不能直接更新curr，不然还原不了现场了

        str.push_back(ch);
        if (next->count > 0)
            ans.insert(str);

        // 优化：删Trie分支
        if (next->child.empty()) {
            curr->child.erase(ch);
            delete (next);
        } else {
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
        }
        // 还原现场
        str.pop_back();
    }
};