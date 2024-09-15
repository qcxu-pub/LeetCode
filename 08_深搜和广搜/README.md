# 1.状态与状态空间

```
状态与状态空间
1.状态：就是程序维护的所有动态数据构成的集合。A={} --> A={1} --> A={1,2} --> ...
2.状态空间：就是所有可能状态构成的集合
3.把问题抽象为树或图的方法：把状态作为点，如果从一个状态到另一个状态连一条边，就把状态空间抽象为了一张有向图。那么对问题的求解就是图的遍历
比如子集的状态空间，每个元素选不选。 比如全排列的状态空间，第一个数选哪个，第二个数选哪个，...

```

# 2.搜索
```
搜索：直接遍历整个状态空间的方法寻找答案。所以根据遍历图方式的不同，可以分为：
1.深度优先搜索 (DFS, depth first search)
2.广度优先搜索 (BFS, breadth first search)
每个状态只遍历1次，所以要注意判重/记忆化

搜索题的解题步骤：
1.纸上模拟，提取变化信息
2.定义状态（变化的信息就是状态）。把状态看做点，变的步骤就是边（分支），形成树/图，这就是状态空间
3.确定遍历顺序 (DFS/BFS)
4.定义搜索框架  --> 动规和图论基础
5.程序实现

搜索实际上就是在 树遍历/图遍历 外面套了一个问题的壳子。所以就增加了一步，怎么把实际问题转化为树/图（+1,+2）

搜索是解决一切问题的万金油算法，众多没有多项式时间解法的问题都需要靠搜索求解

优化：记忆化搜索 - visited数组
```


# 3.深度优先搜索（DFS）

```
搜索框架：状态作为参数，确定递归边界，注意还原现场，考虑是否需要判重
```

- [17. 电话号码的字母组合 (median)](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/17letterCombinations.cpp)

- [51. N 皇后 (hard)](https://leetcode-cn.com/problems/n-queens/) / [52. N皇后 II (hard)](https://leetcode-cn.com/problems/n-queens-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/51solveNQueens.cpp)

- [36. 有效的数独 (median)](https://leetcode-cn.com/problems/valid-sudoku/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/36isValidSudoku.cpp)


# 4.广度优先搜索（BFS）

```
搜索框架：状态用队列保存，考虑是否需要判重
```

- [200. 岛屿数量 (median)](https://leetcode-cn.com/problems/number-of-islands/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/200numIslands.cpp)

- [130. 被围绕的区域 (median)](https://leetcode-cn.com/problems/surrounded-regions/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/130solve.cpp)

- [433. 最小基因变化 (median)](https://leetcode-cn.com/problems/minimum-genetic-mutation/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/433minMutation.cpp)

- [329. 矩阵中的最长递增路径 (hard)](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/329longestIncreasingPath.cpp)



# 5.DFS VS BFS

```
先确定状态空间的形状是树还是图

1.如果是树，用 dfs
  比如：子集，组合，排列。这种分支一层一层往下走，不会产生重复
  因为递归本身就会产生一个树形结构
  可以用共享变量维护比较复杂的信息（比如方案），而且不需要判重，就不需要队列，比较省空间

2.如果是图，且要求min最优解，用 BFS
  比如：最小代价，最少步数，等价于求层数，时间复杂度O(n)
  因为要判重，一定要存东西，那就再开个队列好了
  在广搜里面，队列满足两段单调性：整个队列里面只会有 第level层 和 第level+1层 的元素。因为只有 第level层 算完了，才会扩展 第level+1层 到 level+2 层

3.如果是有向无环图，且要求max最优解，用 BFS拓扑排序/DFS记忆化搜索
  比如：计算最长路径，要考虑所有前驱
  求max就不可能有环，不然有环一直绕圈就无解了

4.图的其他情况：DFS/BFS 都可以

```

# 6.搜索剪枝

```
蛮力搜索（回溯），最原始遍历状态空间的方法，本质上就是试错，一个分支不行，就取消上一步甚至前几步的计算，换个分支重新来过。在分支较多、较深的问题中，容易导致复杂度为指数时间的运算。

剪枝，就是通过已有的信息，提前判定某些分支不可行，或者一定不优，从而减少需要访问的状态空间数量。就像减去搜索树的枝条一样，所以叫剪枝。

```

- [51. N 皇后 (hard)](https://leetcode-cn.com/problems/n-queens/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/51solveNQueens.cpp)

- [22. 括号生成 (median)](https://leetcode-cn.com/problems/generate-parentheses/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/22generateParenthesis.cpp)

- [37. 解数独 (hard)](https://leetcode-cn.com/problems/sudoku-solver/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/08_深搜和广搜/37solveSudoku.cpp)
