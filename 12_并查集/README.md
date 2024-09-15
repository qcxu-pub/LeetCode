
```
并查集(disjoint sets)是一种数据结构

基本用途
1.处理不相交集合的合并和查询问题 --547/200
2.处理分组问题
3.维护无序二元关系 --130

基本操作
1.MakeSet(s): 建立一个新的并查集，s个、每个大小为1的集合
2.UnionSet(x,y): 合并元素x所在集合和元素y所在集合，不相交则合并。如果相交说明x和y在同一集合内就无需合并
3.Find(x): 找到元素x所在集合的代表。每个集合一个代表是固定的，比较代表就可以知道两个集合是否相交

内部操作
每个集合要找固定的代表。所以每个集合是一个树形结构，代表就是根节点
每个结点只需要保存一个值: 它的父节点fa[x]。根节点满足fa[x]=x
合并两个集合，就是先找各自的根，然后把两个根节点合并起来，fa[root1]=root2
合并的时候，按秩合并，把小树的根指向大树的根，这样合并出来的树平衡一点。还要路径压缩，合并时同时改变树的结构，所有结点都连到根节点上，形成深度只有1的一棵树，下次找的时候就一步走到根了  --代码主要是路径压缩，按秩合并并没有...
时间复杂度: 近似O(1)。实际上比O(1)大，但比O(nlogn)小很多。因为树的深度只有1了

class DisjointSet {
    public:

    // MakeSet
    DisjointSet(int n) {
        fa = vector<int>(n,0);
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }

    int find(int x) {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]); //回溯时赋值，实现压缩路径，所有结点都指向根节点
    }

    void unionSet(int x, int y) {
        x = find(x); //返回的是根节点
        y = find(y); //返回的是根节点
        if (x != y)
            fa[x] = y;
    }

    private:
    vector<int> fa;
};

```

- [547. 省份数量 (median)](https://leetcode-cn.com/problems/number-of-provinces/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/12_并查集/547findCircleNum.cpp)

- [130. 被围绕的区域 (median)](https://leetcode-cn.com/problems/surrounded-regions/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/12_并查集/130solve.cpp)

- [145. 超市 (median)](https://www.acwing.com/problem/content/147/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/12_并查集/145maxProfit.cpp)

- [200. 岛屿数量 (median)](https://leetcode-cn.com/problems/number-of-islands/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/12_并查集/200numIslands.cpp)

- [684. 冗余连接 (median)](https://leetcode-cn.com/problems/redundant-connection/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/12_并查集/684findRedundantConnection.cpp)