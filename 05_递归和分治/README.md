# 1.递归

```
递归的三个关键：
1.定义需要递归的问题（重叠子问题）--数学归纳法
2.确定递归边界
3.保护与还原现场

void recursion(int level, int param) {
    // terminal
    if (level > MAX_LEVEL) {
        // process result
        return;
    }
    
    // process logic in current level
    process(level, param);

    // drill down
    recursion(level + 1, new_param);

    // restore the current level status
}

递归的基本形式：暴力搜索，试探分支
1.子集-指数型，时间复杂度k^n，可用于解决：背包问题（物品放还是不放）--体积小动规，体积大递归
2.组合-组合型，时间复杂度n!，可用于解决：组合选数
3.全排列-排列型，时间复杂度n!/(m!*(n-m)!)，可用于解决：旅行商问题（每个城市经过且只经过一次），N皇后问题（n*n棋盘放皇后）
```

- [78. 子集 (median)](https://leetcode-cn.com/problems/subsets/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/78subsets.cpp)

- [77. 组合 (median)](https://leetcode-cn.com/problems/combinations/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/77combine.cpp)

- [46. 全排列 (median)](https://leetcode-cn.com/problems/permutations/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/46permute.cpp)

- [47. 全排列 II (median)](https://leetcode-cn.com/problems/permutations-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/47permuteUnique.cpp)

- [509. 斐波那契数 (easy)](https://leetcode-cn.com/problems/fibonacci-number/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/509fib.cpp)


# 2.分治

```
关键点：
1.分，原问题和子问题同类重复，所以递归解决
2.治，除了向下递归问题，还要向上合并结果
```

- [50. Pow(x, n) (median)](https://leetcode-cn.com/problems/powx-n/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/50myPow.cpp)

- [22. 括号生成 (median)](https://leetcode-cn.com/problems/generate-parentheses/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/22generateParenthesis.cpp)


# 3.二分

```
问题1：等式 - 二分查找
前提：
1.目标函数具有单调性
2.存在上下界
3.能够通过索引访问（链表就不能二分了）

int left = 0, right = n - 1;
while (left <= right) {
    // int mid = (left + right) / 2;  // 可能越界
    int mid = left + (right - left) / 2;
    if (array[mid] == target)
        // find the target
        break or return mid;
    if (array[mid] < target)
        left = mid + 1;
    else
        right = mid - 1;
}
```

```
问题2：不等式 - lower_bound / upper_bound - 这两个都是找后继
1.lower_bound：在递增的数组里，查找第一个 >=x 的数，返回下标
2.upper_bound：在递增的数组里，查找第一个 >x 的数，返回下标


后继型：找第一个 >=target 的数，终止于 left == right

int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (array[mid] >= target) // lower_bound要求的就是>=target的最小值，满足条件。upper_bound这里改成>target
        right = mid; // 包含
    else
        left = mid + 1;  // 不包含
}
return right;


前驱型：找最后一个 <=target 的数，终止于 left == right

int left = -1, right = n - 1;
while (left < right) {
    int mid = (left + right + 1) / 2; // 向上取整。这样只有2个元素的时候，会落在 mid=right 上，而不会在 mid=left 上死循环
    if (array[mid] <= target)
        left = mid;
    else
        right = mid - 1;
}
return right;


问题2的典型应用：不等式条件->0/1分段函数，用二分查找分界点的问题
解题思路：
1.写出二分条件：不等式。代码照抄题目的满足条件
2.满足就是要mid，条件放到if里。要小的->去左边->right=mid，要大的->去右边->left=mid
3.另一半不满足的放else里，不要mid。left=mid+1 / right=mid-1。后者求mid时要+1求上界
4.无解时，上界+1 / 下界-1
```

```
问题3：实数二分
就不用考虑left/right哪边要mid，哪边不要mid的问题了
```

- [704. 二分查找 (easy)](https://leetcode-cn.com/problems/binary-search/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/704search.cpp)

- [153. 寻找旋转排序数组中的最小值 (median)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/153findMin.cpp)

- [154. 寻找旋转排序数组中的最小值 II (hard)](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/154findMin.cpp)

- [34. 在排序数组中查找元素的第一个和最后一个位置 (median)](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/34searchRange.cpp)

- [69. x 的平方根  (easy)](https://leetcode-cn.com/problems/sqrtx/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/69mySqrt.cpp)

- [74. 搜索二维矩阵 (median)](https://leetcode-cn.com/problems/search-a-2d-matrix/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/74searchMatrix.cpp)

- [240. 搜索二维矩阵 II (median)](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/240searchMatrix.cpp)

- [33. 搜索旋转排序数组 (median)](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/33search.cpp)

- [39. 组合总和 (median)](https://leetcode-cn.com/problems/combination-sum/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/39combinationSum.cpp)

- [79. 单词搜索 (median)](https://leetcode-cn.com/problems/word-search/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/79exist.cpp)



# 4.三分

```
二分：用于在单调函数上寻找特定值
三分：用于在单峰函数上寻找极大值/单谷极小值

单峰函数：分段严格单调递增/递减（不能出现一段平的）

三分，就是把区间分成三段：[left,lmid,rmid,right]，每一次通过判断，可以缩掉1/3
1.当 f[lmid]<f[rmid] 时，上升段，极大值target两种可能：[rmid,right],[lmid,rmid]，不可能落在[left,lmid]里面
2.当 f[lmid]>f[rmid] 时，下降段，极大值target两种可能：[left,lmid],[lmid,rmid]，不可能落在[rmid,right]里面
其中，lmid,rmid 的取法，可以是三等分点，也可以是 lmid二等分点/rmid稍加一点偏移量。取黄金分割点是最快的
```

- [162. 寻找峰值 (median)](https://leetcode-cn.com/problems/find-peak-element/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/162findPeakElement.cpp)


# 5.二分答案

```
二分答案，是把最优性问题转化为判定问题的基本技巧
最优性问题：求最大值/最小值
判定：给一个解，判断它是否合法（是否能够实现）
二分答案：如果解空间有单调性，就可以用二分法枚举+判定一遍

通常用于最优化问题的求解。这类题目常见的字眼：最大值最小，最小值最大
比如：最大值最小，“最小”是最优化目标，求的是最小值。“最大”是限制条件
对应的判定问题的条件通常是个不等式，不等式反映了上述限制条件
关于这个条件的合法情况，具有特殊单调性（解>=某个值，或者<=某个值，解才能算合法）
这时就可以用二分答案，把求解转化为判定问题

所以，二分答案的本质，就是建立一个单调分段0/1函数，定义域是解空间（答案），值域为0/1。
这个函数就是验证。在这个函数上二分查找分界点
```

- [374. 猜数字大小 (easy)](https://leetcode-cn.com/problems/guess-number-higher-or-lower/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/374guessNumber.cpp)

- [410. 分割数组的最大值 (hard)](https://leetcode-cn.com/problems/split-array-largest-sum/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/410splitArray.cpp)

- [1482. 制作 m 束花所需的最少天数 (median)](https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/1482minDays.cpp)

- [1011. 在 D 天内送达包裹的能力 (median)](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/1011shipWithinDays.cpp)

- [911. 在线选举 (median)](https://leetcode-cn.com/problems/online-election/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/911TopVotedCandidate.cpp)

- [875. 爱吃香蕉的珂珂 (median)](https://leetcode-cn.com/problems/koko-eating-bananas/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/05_递归和分治/875minEatingSpeed.cpp)

