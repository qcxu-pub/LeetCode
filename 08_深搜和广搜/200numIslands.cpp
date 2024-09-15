#include <vector>
#include <queue>
using namespace std;

/*
200. 岛屿数量
https://leetcode-cn.com/problems/number-of-islands/

思路：
地图类DFS/BFS，用方向数组
这题本质是在图中划分连通块，用判重
找到一个没有访问过的1，利用DFS/BFS把连通的都找出来，标记已访问。这样调用几次DFS/BFS就有多少连通块

后面还可以用并查集做
*/

class Solution {
    public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool> >(m, vector<bool>(n, false));
        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    private:
    vector<vector<char> > grid;
    int m, n;
    vector<vector<bool> > visited;

    void bfs(int sx, int sy) {
        queue<pair<int, int> > q;
        q.push(make_pair(sx, sy));

        // 定义方向数组
        const int dx[4] = {0,1,0,-1};
        const int dy[4] = {1,0,-1,0};
        while (!q.empty()) {
            // 1.取队头
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visited[x][y] = true;
            // 2.扩展队头
            for (int i=0; i<4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m  || ny < 0 || ny >= n)
                    continue;
                if (visited[nx][ny])
                    continue;
                if (grid[nx][ny] == '0')
                    continue;
                bfs(nx, ny);
            }
        }
    }
};