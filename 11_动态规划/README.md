# 1.动态规划总论(DP, Dynamic Programming)

```
为什么要动态规划算法？
解题思路其实还是从搜索出发。但搜索很慢（可以看322题例子）
动态规划的本质，就是对状态空间的按阶段有序不重复遍历，提炼最优子结构为代表做递推，然后相当于在以状态为点的图上进行拓扑排序


什么是动态规划算法？
无论是 递推 实现，还是 递归+记忆化搜索 实现，都是
1.从搜索出发，人工模拟，蛮力搜索 --> 关注轮廓变化，就是dfs的参数共享变量，这就是状态
2.定义状态 --> 关注代表，以及他们之间的推导关系，这就是最优子结构
3.确定最优子结构
4.写出状态转移方程，就是模拟时的决策
5.确定边界、目标，递推实现（边界包括：起点、会访问到的不合法状态）
以上可看到，动态规划本质就是对搜索的优化，怎么提炼最优子结构


动态规划的关键与前提
1.重叠子问题：跟递归、分治一样 --> 找状态
2.最优子结构：每个状态对应着一个最优化目标（就是一组状态的代表），这些代表之间有推导关系 --> 动规核心
3.无后效性：问题的状态空间是有向无环图，就是可以按一定的顺序遍历求解


动规三要素：阶段，状态，决策

opt[0] = 0;
// 这里的 i 是阶段，线性增长
for (int i = 1; i <= amount; ++i) {
    opt[i] = INF;
    for (int j = 0; j < coins.length(); ++j) {
        if (i - coins[i] >= 0)
            // 这里的 coins[j] 是决策，找到重叠子问题
            // 这里的 opt[i] 是状态，具有最优子结构，一堆方案的代表
            opt[i] = min(opt[i], opt[i - coins[j]] + 1); // 状态转移方程
    }
}


动规的标准题解 (跟上面的代码可以对应)
设 opt[i] 表示凑成 金额i 所需的最少硬币数
状态转移方程: opt[i] = min(opt[i-coin]), for coin in coins  --> 核心
边界: opt[0] = 0, opt[i] = MAX_INF (i>0)
目标: opt[amount]
时间复杂度: O(amount * |coins|)


动规题目打印方案的通用做法
记录转移路径 + 递归输出
就是记一下每个f[i]是从哪里转移过来的，不要记录每一步方案

```

- [322. 零钱兑换 (median)](https://leetcode-cn.com/problems/coin-change/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/322coinChange.cpp)

- [63. 不同路径 II (median)](https://leetcode-cn.com/problems/unique-paths-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/63uniquePathsWithObstacles.cpp)

- [1143. 最长公共子序列 (median)](https://leetcode-cn.com/problems/longest-common-subsequence/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/1143longestCommonSubsequence.cpp)

- [300. 最长递增子序列 (median)](https://leetcode-cn.com/problems/longest-increasing-subsequence/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/300lengthOfLIS.cpp)

- [53. 最大子数组和 (easy)](https://leetcode-cn.com/problems/maximum-subarray/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/53maxSubArray.cpp)

- [152. 乘积最大子数组 (median)](https://leetcode-cn.com/problems/maximum-product-subarray/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/152maxProduct.cpp)

- [70. 爬楼梯 (easy)](https://leetcode-cn.com/problems/climbing-stairs/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/70climbStairs.cpp)

- [120. 三角形最小路径和 (median)](https://leetcode-cn.com/problems/triangle/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/120minimumTotal.cpp)

- [673. 最长递增子序列的个数 (median)](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/673findNumberOfLIS.cpp)

- [72. 编辑距离 (hard)](https://leetcode-cn.com/problems/edit-distance/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/72minDistance.cpp)

- [45. 跳跃游戏 II (median)](https://leetcode-cn.com/problems/jump-game-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/45jump.cpp)

- [55. 跳跃游戏 (median)](https://leetcode-cn.com/problems/jump-game/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/55canJump.cpp)

- [32. 最长有效括号 (hard)](https://leetcode-cn.com/problems/longest-valid-parentheses/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/32longestValidParentheses.cpp)

- [62. 不同路径 (median)](https://leetcode-cn.com/problems/unique-paths/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/62uniquePaths.cpp)

- [64. 最小路径和 (median)](https://leetcode-cn.com/problems/minimum-path-sum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/64minPathSum.cpp)

- [221. 最大正方形 (median)](https://leetcode-cn.com/problems/maximal-square/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/221maximalSquare.cpp)


# 2.股票买卖系列问题

```
共同点：都是price数组买卖股票，任何时刻只能持1股
不同点：交易次数(1次/2次/c次/无限次)，是否有手续费，是否有冷冻期

固有量：price数组，是否有手续费
变量->状态：第i天，当前仓位是否有股票j，已交易次数k，是否在冷冻期l --> 4维状态 f[i,j,k,l]
状态转移方程:
    买: f[i,1,k,0] = max(f[i,1,k,0], f[i-1,0,k-1,0] - prices[i] - fee)
    卖: f[i,0,k,1] = max(f[i,0,k,1], f[i-1,1,k,0] + prices[i])
    啥也不干: f[i,j,k,0] = max(f[i,j,k,0], f[i-1,j,k,l]), 其中, l = 0 or 1
边界: f[0,0,0,0] = 0, 其余负无穷
目标: max{f[n,0,k,l]}
时间复杂度: O(n*c)

121/123/188: i,j,k
122/309: i,j
714: i,j,l

```

```
思考1: 与贪心的对比
无数次交易，可贪心
有交易k次限制，不可贪心，得全局考量
所以，蛮力搜索 --> 同类子问题 --> 最优子结构 --> 动态规划。这个才是正常的思考路径。不能盲目贪心


思考2: 空间和时间怎么平衡
122题，f[i,j]表示第i天结束时，持有j股股票(0/1)的最大收益
由于若干次交易是不能同时进行的，也就是不能交叉，就可以这样简化状态（类似于之前LIS的思想，到当前的最佳状态）:
f[i]表示第i天结束，且刚好完成一笔交易时的最大收益
   j     i
   _     _
  | |   | | 
3 2 6 5 0 3

f[i] = max{f[j] + prices[i] - min{prices[k]}}
其中，max范围是 0<=j<=i-2, min范围是 j<k<i
f[j] 是上一次完成交易的收益，prices[i] - min{prices[k]} 是这次交易的最大收益
明显这个决策比之前复杂多了。。虽然它省了空间

所以，状态包含的信息越多，决策越简单；状态越简单，决策越复杂
所以，尽量把关注的信息都放在状态里面，除非最后状态规模太大再考虑优化


思考3: 状态转移方程的两种写法
上面的解法是，f[i,j,k,l]怎么算，就是说，今天的这个状态是有哪里转移过来的。也就是，当前结点 & 入边
还有一种思路是，当前结点 & 出边。也就是，f[i,j,k,l]能更新到哪些状态
第二种思路可以用列表法: 当前状态是 f[i,j,k,l]。第i天，当前仓位是否有股票j，已交易次数k，是否在冷冻期l

下一天干啥     条件           代价/收益           完成之后的状态
  buy      j=0,k<c,l=0     -prices[i+1]-fee    f[i+1,1,k+1,0]
  sell     j=1,l=0         prices[i+1]         f[i+1,0,k,1]
  reset    --                   0              f[i+1,j,k,0]

（下一天干啥，就是决策，共三个分支）
这样照着表就可以写出状态转移方程。以sell为例:
if (j==1 && l==0) f[i+1,0,k,1] = max(f[i+1,0,k,1], f[i,j,k,l] + prices[i+1])


思考4: 空间的优化 -- 滚动数组
f[i,?,?,?] 总是从 f[i-1,?,?,?] 转移过来的，跟更早的 i-2, i-3, ... 无关
如果把每个 f[i] 看做一行，那么转移只会发生在相邻两行。那之前的空间可以回收
这种情况可以使用滚动数组

实现中，先不优化，写完之后在每个 i 后面 &1 (and 1, 相当于 mod 2) --位运算
& 优先级 小于 +/-，所以都可以不用加()
注意，要初始化复用的空间


思考5: d天冷冻期?
多的信息，全都往状态放就好了。只有完成之后的状态变了

下一天干啥     条件           代价/收益           完成之后的状态
  buy      j=0,k<c,l=0     -prices[i+1]-fee    f[i+1,1,k+1,0]
  sell     j=1,l=0         prices[i+1]         f[i+1,0,k,d]
  reset    --                   0              f[i+1,j,k,max(l-1,0)]


思考6: 最多持仓t股?
f[i,j,k,l] 表示第i天结束，持有j股股票，已经交易了k次，冷冻期还有l天时的最大收益

下一天干啥     条件           代价/收益           完成之后的状态
  buy      j<t,k<c,l=0     -prices[i+1]-fee    f[i+1,j+1,k+1,0]
  sell     j>0,l=0         prices[i+1]         f[i+1,j-1,k,d]
  reset    --                   0              f[i+1,j,k,max(l-1,0)]

如果每天可以买卖<=t股，那每次交易必然以t股为单位最优，那么 j=0 or j=t。这样就可以用贪心了。

```

- [121. 买卖股票的最佳时机 (easy)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/188maxProfit.cpp)

- [122. 买卖股票的最佳时机 II (median)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/122maxProfit.cpp)

- [123. 买卖股票的最佳时机 III (hard)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/188maxProfit.cpp)

- [188. 买卖股票的最佳时机 IV (hard)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/188maxProfit.cpp)

- [309. 最佳买卖股票时机含冷冻期 (median)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/309maxProfit.cpp)

- [714. 买卖股票的最佳时机含手续费 (median)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/714maxProfit.cpp)


# 3.打家劫舍系列问题

```
198 线性动规
213 环形动规
337 树形动规
```

- [198. 打家劫舍 (median)](https://leetcode-cn.com/problems/house-robber/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/198rob.cpp)

- [213. 打家劫舍 II (median)](https://leetcode-cn.com/problems/house-robber-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/213rob.cpp)

- [337. 打家劫舍 III (median)](https://leetcode-cn.com/problems/house-robber-iii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/337rob.cpp)


# 4.背包问题

```
0/1背包问题

已知：N个物品，其中第i个物品的体积为Vi，价值为Wi。有一个背包容积M
求解：物品放入背包，体积不超过M的情况下，使价值最大

朴素：每个物品选or不选，子集问题，O(2^n)
状态变量: 每个物品选or不选，当前背包里面已经放了多少体积的东西了(要<M)
价值最大化，最优化问题。最优子结构：考虑前i个物品，取总体积为j的物品，拿价值最大的方案作为代表，具体怎么拿不关心
状态转移:
    不选第i个物品: f[i,j] = f[i-1,j]
    选第i个物品:   f[i,j] = f[i-1,j-vi] + wi  (if j>=vi)
初值: f[0,0]=0。其余都是负无穷，因为要求max
目标: max{f[n,j]} (0<=j<=M)


vector<vector<int>> f(n + 1, vector<int>(m + 1, -1e9));
f[0][0] = 0;
for (int i = 1; i <= n; ++i) {
    // 不选 第i个物品
    for (int j = 0; j <= m; ++j) {
        f[i][j] = f[i-1][j];         // 相当于把f[i-1]copy到了f[i]，这样可以把i这个维度省掉
    }
    // 选 第i个物品
    for (int j = v[i]; j <= m; ++j) {
        f[i][j] = max(f[i][j], f[i-1][j - v[i]] + w[i]);
    }
}
int ans = 0;
for (int j = 0; j <= m; ++j) {
    ans = max(ans, f[n][j]);
}
return ans;


优化为一维数组。因为 第 i 个状态都是从 i-1 这边转移过来的
vector<vector<int>> f(m + 1, -1e9);
f[0] = 0;
// 第一维虽然可以省，但还是得循环。要不要第i个物品
for (int i = 0; i <= n; ++i) {
    // 这里必须倒序遍历
    // 如果要选第i个物品，体积变化可以是j-v[i]->j，也可以是j->j+v[i]
    // 但只能选一次第i个物品。如果正序算，就选了多次第i个物品，体积累积了。但这里是0/1背包问题，只能选一次
    for (int j = m; j >= v[i]; --j) {
        f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
}
int ans = 0;
for (int j = 0; j <= m; ++j) {
    ans = max(ans, f[j]);
}
return ans;

```

```
完全背包问题

已知：N个物品，其中第i个物品的体积为Vi，价值为Wi，并且有无数多个。有一个背包容积M
求解：物品放入背包，体积不超过M的情况下，使价值最大

状态变量: f[i,j]表示，从前i种物品中，选出了总体积为j的物品放入背包，物品的最大价值和
状态转移:
    不选: f[i,j] = f[i-1,j]
    选:   f[i,j] = f[i-1, j - k * vi] + k * wi  --这样要枚举k选几个，麻烦

    把选的情况拆一拆:
    k=0,还没有选过第i个物品: f[i,j] = f[i-1,j]   --> 同样是copy，所以第一维可以省掉，只开一维数组空间
    k>=1,从第i个物品中选1个: f[i,j] = f[i,j-vi] + wi  (if j>=vi)  --因为没选过的情况已经从[i-1]过渡到[i]了。这是跟0/1背包的唯一区别

初值: f[0,0]=0。其余都是负无穷，因为要求max
目标: max{f[n,j]} (0<=j<=M)


vector<int> f(m + 1, -1e9);
f[0] = 0;
// for物品
for (int i = 1; i <= n; ++i) {
    // for体积。正序循环就是完全背包了。因为第i个物品可以重复选了。
    for (int j = v[i]; j <= m; ++j) {
        f[j] = max(f[j], f[j - v[i]] + w[i]);  // 这里可以根据题目改。最优解min/max，可行性|=，方案数+=
    }
}
int ans = 0;
for (int j = 0; j <= m; ++j)
    ans = max(ans, f[j]);

```

- [416. 分割等和子集 (median)](https://leetcode-cn.com/problems/partition-equal-subset-sum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/416canPartition.cpp)

- [518. 零钱兑换 II (median)](https://leetcode-cn.com/problems/coin-change-2/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/518change.cpp)

- [279. 完全平方数 (median)](https://leetcode-cn.com/problems/perfect-squares/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/279numSquares.cpp)


# 5.动态规划的优化

```
引入

给定n个二元组 (x1,y1),(x2,y2),...,(xn,yn)，已按x从小到大排序
求: yi + yj + |xi - xj| 的最大值 (i ≠ j)

朴素: O(2^n)
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (i != j)
            ans = max(ans, y[i] + y[j] + abs(x[i] - x[j]));
    }
}

找冗余。两个端点问题，i和j是否跟顺序有关？无关！所有有了下里面的优化
设 j < i, O(2^n/2)
for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
        ans = max(ans, y[i] + y[j] + x[i] - x[j]);
    }
}

固定i，发现 y[i] + x[i] 是不变的。所有有了下面的优化
没啥用。。还是 O(2^n) 的复杂度
for (int i = 2; i <= n; ++i) {
    int temp = -1e9;
    for (int j = 1; j < i; ++j) {
        temp = max(temp, y[j] - x[j]);
    }
    ans = max(ans, y[i] + x[i] + temp);
}

手动执行一下上面的代码，找找冗余
i=2, j=1, max{y[1]-x[1]}
i=3, j=1,2, max(y[1]-x[1], y[2]-x[2])
i=4, j=1,2,3, max(y[1]-x[1], y[2]-x[2], y[3]-x[3])
i=5, j=1,2,3,4, max(y[1]-x[1], y[2]-x[2], y[3]-x[3], y[4]-x[4])

冗余找到了。比如，i=5 算max，只要 i=4 的结果上继续做就好了
这样优化时间复杂度就变成 O(n)
int temp = -1e9;
for (int i = 2; i <= n; ++i) {
    temp = max(temp, y[i-1] - x[i-1]);
    ans = max(ans, y[i] + x[i] + temp);
}

总结一下，这里的优化主要靠两点：
1.分离 i 和 j。与 i 有关的式子放一边，与 j 有关的式子放一边，不要互相干扰
2.观察内层循环变量 j 的取值范围随着外层循环变量的变化情况

进一步思考
这个例子可以变成“树的直径”问题。x是树的主干，每个y都是树的分支

```

```
动态规划的优化：优化掉决策循环 --重回滑动窗口

动态规划的情况跟上面那个例子很像。i 是状态，j 是决策。状态变量在外层，里面是决策
所以根据上面的例子，动态规划可以有这样的优化：
1.分离状态变量和决策变量。当循环多于两重时，把外层看做定值，关注最里边是怎么变的
2.对于一个状态变量，决策变量的取值范围称为“决策候选集合”，观察这个集合随着状态变量的变化情况

```

- [1499. 满足不等式的最大值 (hard)](https://leetcode-cn.com/problems/max-value-of-equation/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/1499findMaxValueOfEquation.cpp)

- [918. 环形子数组的最大和 (median)](https://leetcode-cn.com/problems/maximum-sum-circular-subarray/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/918maxSubarraySumCircular.cpp)


# 6.区间动态规划

```
以前的分治，是分成左右两个部分，分别递归处理。可以用一个区间表示一个子问题，用一个小区间递归。这就是dfs+记忆化搜索
或者把区间看成一个阶段，先算小区间，再算长区间，for循环，按区间长度递推
这种基于f[l,r]一个区间的最优化子问题，就是区间动规。有上面两种写法

区间动态规划的子问题是基于一个区间的
阶段: 区间长度。最外层循环不是 for l for r，而是 for 区间长度
状态: 区间端点。放第二层循环里面
决策: 按题目意思来
在计算区间长度为len的子问题时，要先算好所有长度<len的子问题。先算小区间，再算大区间，元区间作为边界
```

- [312. 戳气球 (hard)](https://leetcode-cn.com/problems/burst-balloons/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/312maxCoins.cpp)

- [1000. 合并石头的最低成本 (hard)](https://leetcode-cn.com/problems/minimum-cost-to-merge-stones/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/1000mergeStones.cpp)

- [516. 最长回文子序列 (median)](https://leetcode-cn.com/problems/longest-palindromic-subsequence/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/516longestPalindromeSubseq.cpp)

- [96. 不同的二叉搜索树 (median)](https://leetcode-cn.com/problems/unique-binary-search-trees/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/96numTrees.cpp)

- [139. 单词拆分 (median)](https://leetcode-cn.com/problems/word-break/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/139wordBreak.cpp)

- [887. 鸡蛋掉落 (hard)](https://leetcode-cn.com/problems/super-egg-drop/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/887superEggDrop.cpp)


# 7.树形动态规划

```
跟线性动态规划没有本质区别。只是套在深度优先遍历里的动态规划
子问题: 叶子 --> 子树 --> 一颗完整的树
状态: 以 x 为根的子树
决策: 从子节点到父节点
可以根据题目的复杂程度，增加与题目相关的状态和决策


跟区间动态规划也有相似处：

l  x  x  x  x  x  x  x  x  x  x  r
l1 x  x  x  x  r1 l2 x  x  x  x  r2
l3 x  r3 l4 x  r4 l5 x  r5 l6 x  r6 
......... (可以形成元区间) .........

区间动态规划
阶段: 区间长度
状态: f[l,r]为状态
状态转移: 发生在小区间到大区间。元区间 --> 小区间 --> 大区间 --> 整个区间[1,n]。在树上的表现是，从下往上

树形动态规划
阶段: 树的level
状态: 具体子树
状态转移: 发生在子节点到父节点。一个区间相当于一个树结点。叶子结点 --> 小子树 --> 大子树 --> 根节点

所以树形动态规划就是，先探下去，然后回溯的时候，从下往上算，先想子树怎么样
```

- [124. 二叉树中的最大路径和 (hard)](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/11_动态规划/124maxPathSum.cpp)

