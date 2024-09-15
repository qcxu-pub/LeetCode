#include <vector>
using namespace std;

/*
684. 冗余连接
https://leetcode-cn.com/problems/redundant-connection/

找出让树变成基环树（图）的罪魁祸首

思路：图的深度优先遍历
出边数组在加边的时候，加一条就判一下有没有成环
判断环的依据是：递归到之前遍历过的点，且不是自己的父亲结点
时间复杂度 O(n^2)

后面还可以用并查集做
*/

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        // 更新n
        n = 0;
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            n = max(n, max(x, y));
        }

        // 出边数组加边
        to = vector<vector<int> >(n + 1, vector<int>());
        visited.resize(n + 1, false);
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            to[x].push_back(y);
            to[y].push_back(x);

            hasCycle = false;
            for (int v : visited)
                v = false;
            dfs(x, 0);
            if (hasCycle)
                return edge;
        }
        return {};
    }

   private:
    int n;
    vector<vector<int> > to;
    bool hasCycle;
    vector<bool> visited;

    // dfs遍历出边数组判断是否有环
    void dfs(int x, int father) {
        visited[x] = true;
        for (int y : to[x]) {
            if (y == father)
                continue;
            if (visited[y]) {
                hasCycle = true;
                return;
            } else {
                dfs(y, x);
            }
        }
        visited[x] = false;
    }
};