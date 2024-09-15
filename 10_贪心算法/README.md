```
什么是贪心算法？
1.在每一步选择中都采取：在当前状态下的最优决策（局部最优）。因为状态空间是图，每个状态一个分支，挑最好的那个走，同时不再回头 
2.希望由此导致最终结果也是全局最优。希望说明不一定是对的，要证明


对比：搜索 VS 贪心 VS 动规
相同点：都是基于状态
不同点：
1.搜索和动规是遍历整个状态空间的，所以结果是对的。搜索是蛮力遍历，动规是把状态分阶段，更高级一点
2.贪心只遍历一部分状态。局部最优解，一步一步走下去，不能回溯。所以用贪心的时候要证明，每一步选局部最优解，最后能得到全局最优解。贪心优点只是快

所以先想搜索和动规，对状态空间有一个了解。不要先想贪心。只想用贪心加速。
贪心要证明可行性：
1.决策包容性
2.拓展决策范围
3.邻向交换
```

# 1.贪心算法要满足决策包容性

- [860. 柠檬水找零 (easy)](https://leetcode-cn.com/problems/lemonade-change/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/10_贪心算法/860lemonadeChange.cpp)

- [455. 分发饼干 (easy)](https://leetcode-cn.com/problems/assign-cookies/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/10_贪心算法/455findContentChildren.cpp)


# 2.扩展决策范围，多往后看一步

```
在思考贪心算法时，有时候不容易直接证明局部最优决策的正确性。
这个时候可以往后多扩展一步，有助于当前决策进行验证。
```

- [122. 买卖股票的最佳时机 II (median)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/10_贪心算法/122maxProfit.cpp)

- [45. 跳跃游戏 II (median)](https://leetcode-cn.com/problems/jump-game-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/10_贪心算法/45jump.cpp)

- [55. 跳跃游戏 (median)](https://leetcode-cn.com/problems/jump-game/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/10_贪心算法/55canJump.cpp)


# 3.邻向交换法

```
用于求顺序。贪心会认为按某种顺序排列是最优的。
在任意局面下，逆序的方向交换是不好的。所以对逆序的做邻向交换，把逆序变有序。
冒泡排序的思想。
```

- [1665. 完成所有任务的最少初始能量 (hard)](https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/10_贪心算法/1665minimumEffort.cpp)
