#include <vector>
using namespace std;

/*
547. 省份数量（原朋友圈）
https://leetcode-cn.com/problems/number-of-provinces/

可以用bfs做。这里用并查集做
结点=城市
边=城市是否相连
连通块=省份

*/

class Solution {
   public:
    int findCircleNum(vector<vector<int> >& isConnected) {
        int n = isConnected.size();
        fa = vector<int>(n, 0);

        // MakeSet
        for (int i = 0; i < n; ++i)
            fa[i] = i;

        // unionSet。对于每条边，把两个集合合并
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    unionSet(i, j);
                }
            }
        }

        // 根节点的数量，就是省份的数量
        // 代表是本身的，就是根节点
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i)
                ans++;
        }
        return ans;
    }

   private:
    vector<int> fa;

    int find(int x) {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y) {
        // 找根节点作为代表
        int fx = find(x);
        int fy = find(y);

        // 代表不同则合并
        if (fx != fy)
            fa[fx] = fy;
    }
};