#include <queue>
#include <vector>
using namespace std;

/*
1245. 树的直径
给你一颗无向树，请你测算并返回它的直径：这颗树上最长简单路径的边数
我们用一个由所有边组成的数组 edges 来表示一颗无向树，其中 edges[i] - [u,v]
表示节点 u 和 v 之间的双向边。 树上的节点都已经用 [0,1,...,edges.length]
中的数做了标记，每个节点上的标记都是独一无二的

例如：edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]  --> 输出:4  --> 3-2-1-4-5

无向树，其实就是n个点，n-1条边的连通无向图

结论：
1.从任意点出发，找到距离它最远的点p
2.从p出发，找到距离它最远的点q
3.pq的路径就是树的直径

推导：反证法
假设从O点出发最远到点p，但树的直径是rq，两条线相交于x
OP最远，说明 px=op-ox > rx=or-ox，所以 pq=px+xq > rq=rx+xq
这样就与 rq 是树的直径矛盾。树的直径是 pq
所以先找到从O点出发最远到点p，然后再找从p出发最远到q，pq就是树的直径

求最远距离，就是深度优先/广度优先遍历
*/

class Solution {
   public:
    int treeDiameter(vector<vector<int> >& edges) {
        n = 0;
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            n = max(n, max(x, y));
        }
        n++;

        for (int i = 0; i < n; ++i) {
            to.push_back({});
        }
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            to[x].push_back(y);
            to[y].push_back(x);
        }
        int p = findFarthest(0).first;
        return findFarthest(p).second;
    }

   private:
    int n;
    vector<vector<int> > to;  // 出边数组

    // <最远点，最远距离>
    pair<int, int> findFarthest(int start) {
        vector<int> depth(n, -1);
        queue<int> q;
        q.push(start);
        depth[start] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : to[x]) {
                // 走过了
                if (depth[y] != -1)
                    continue;
                depth[y] = depth[x] + 1;
                q.push(y);
            }
        }

        int ans = start;
        for (int i = 0; i < n; ++i) {
            if (depth[i] > depth[ans]) {
                ans = i;
            }
        }
        return {ans, depth[ans]};
    }
};