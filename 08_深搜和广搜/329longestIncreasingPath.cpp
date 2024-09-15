#include <queue>
#include <vector>
using namespace std;

/*
329. 矩阵中的最长递增路径
https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/

本题是求最长路径。BFS/DFS都可以解决这个问题。
BFS是从起点出发，到当前点的最长长度。是自顶向下的过程
DFS是从当前点出发，最远能走到哪里。走到底不能再走了，回溯的时候+1，是自底向上的过程
这是下面两个代码dist的不同含义
*/


/*
BFS思路
存在子路径长度重复计算的问题。那就是希望之前的子路径都求过了。那就转化为图拓扑排序的问题了，且因为每一步都递增所以不可能存在环。
所以，从每个点到相邻的比它大的点画边，完成建图（出边数组），然后拓扑排序（从入度为0的点开始扩展）。
拓扑排序跟一般BFS区别在于，一般BFS用来求层数最少，所以越早入队越好。但拓扑排序主要求路径最长，所以是越晚入队越好，而晚入队是靠入度减到0后入队来控制。
*/

class Solution {
   public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        to = vector<vector<int> >(m * n);
        inDeg = vector<int>(m * n, 0);
        dist = vector<int>(m * n, 0);

        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        // 建图
        // cout << "----- index_1d:matrix_value ------" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    // cout << "(i,j)=(" << i << "," << j << ") -- > (ni,nj)=(" << ni << "," << nj << "), isValid(ni,nj)=" << isValid(ni,nj) << endl;
                    if (isValid(ni, nj) && matrix[ni][nj] > matrix[i][j]) {
                        addEdge(num(i, j), num(ni, nj));
                        // cout << num(i,j) << ":" << matrix[i][j] << " --> " << num(ni,nj) << ":" << matrix[ni][nj] << endl;
                    }
                }
            }
        }
        // cout << " ----- build end -------" << endl;

        // 拓扑排序第1步：找入度为0的点，入队
        for (int i = 0; i < inDeg.size(); ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
                dist[i] = 1;
            }
        }

        // bfs
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            // 拓扑排序第2步：头结点扩展，遍历出边数组，周围点入度-1
            for (int y : to[x]) {
                inDeg[y]--;
                dist[y] = max(dist[y], dist[x] + 1);
                // 拓扑排序第3步：入度为0，则入队
                if (inDeg[y] == 0)
                    q.push(y);
            }
        }

        // 找出最大的dist
        int ans = 0;
        for (int d : dist) {
            ans = max(ans, d);
        }
        return ans;
    }

   private:
    int m, n;
    vector<vector<int> > to;
    vector<int> inDeg;
    queue<int> q;
    vector<int> dist;

    int num(int i, int j) {
        return i * n + j;
    }

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void addEdge(int u, int v) {
        to[u].push_back(v);
        inDeg[v]++;
    }
};


/*
DFS思路
因为存在子路径重复计算的问题，所以采用记忆化搜索
*/

class Solution2 {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        m = matrix.size();
        n = matrix[0].size();
        dist = vector<vector<int>>(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }

   private:
    vector<vector<int>> matrix;
    int m, n;
    vector<vector<int>> dist;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};

    int dfs(int x, int y) {
        // 记忆化
        if (dist[x][y] > 0)
            return dist[x][y];

        dist[x][y] = 1;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                dist[x][y] = max(dist[x][y], dfs(nx, ny) + 1);
            }
        }
        return dist[x][y];
    }

    bool isValid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }
};

