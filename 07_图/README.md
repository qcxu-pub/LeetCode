```
链表是特殊的树，树是特殊的图。

图有三种存储方法：
1.邻接矩阵: n*n 的矩阵，(n,n)这条边是否连通。稀疏矩阵，空间利用率低。O(n^2)
           int graph[MAX_N][MAX_N];
           gragh[x][y] = 1;
2.出边数组: x->y, x->z <==> to[x] = {y,z}。这种方法比较常用。O(n+m)
           vector<int> graph[MAX_N];
           graph[x].push_back(y);
3.邻接表: 所有结点放在数组里，每个数组元素后面挂链表，表示该元素可以到的点。相当于把出边数组里的数组，改成了链表。O(n+m)
            // 定义
            struct Node {
                int to;
                Node* next;
            };
            Node* head[MAX_N];
            // 新增边(x,y)，插入链表头部
            Node* node = new Node();
            node->to = y;
            node->next = head[x];
            head[x] = node;

两类问题：
深度优先遍历：划分连通块，找环
广度优先遍历：拓扑排序
```

# 1.深度优先遍历

- [684. 冗余连接 (median)](https://leetcode-cn.com/problems/redundant-connection/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/07_图/684findRedundantConnection.cpp)

# 2.广度优先遍历

- [207. 课程表 (median)](https://leetcode-cn.com/problems/course-schedule/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/07_图/207canFinish.cpp)

- [210. 课程表 II (median)](https://leetcode-cn.com/problems/course-schedule-ii/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/07_图/210findOrder.cpp)
