#include <vector>
using namespace std;

/*
684. 冗余连接
https://leetcode-cn.com/problems/redundant-connection/

图的那章用了dfs。这里用并查集做

一条一条边加，如果一条边的两个点属于同一个根，就说明这条边会让树成环
*/

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();

        // 初始化根 fa
        makeSet();

        for (int i = 0; i < n; ++i) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];

            // 判断是否是同一个根
            int fa1 = find(node1);
            int fa2 = find(node2);
            if (fa1 == fa2)
                return edges[i];

            // 不是同一个根，就更新fa
            unionSet(node1, node2);
        }
        return {};
    }

   private:
    int n;
    vector<int> fa;

    void makeSet() {
        fa = vector<int>(1001, 0);  // 3 <= n <= 1000
        for (int x = 0; x <= 1000; ++x)
            fa[x] = x;
    }

    int find(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
            fa[fx] = fy;
    }
};