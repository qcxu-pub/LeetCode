# 1.基础题目

- [66. 加一 (easy)](https://leetcode-cn.com/problems/plus-one/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/66plusOne.cpp)

- [31. 下一个排列 (median)](https://leetcode.cn/problems/next-permutation/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/31nextPermutation.cpp)

- [48. 旋转图像 (median)](https://leetcode.cn/problems/rotate-image/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/48rotate.cpp)

- [54. 螺旋矩阵 (median)](https://leetcode.cn/problems/spiral-matrix/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/54spiralOrder.cpp)

- [59. 螺旋矩阵 II (median)](https://leetcode.cn/problems/spiral-matrix-ii/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/59generateMatrix.cpp)

- [498. 对角线遍历 (median)](https://leetcode.cn/problems/diagonal-traverse/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/498findDiagonalOrder.cpp)

- [128. 最长连续序列 (median)](https://leetcode.cn/problems/longest-consecutive-sequence/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/128longestConsecutive.cpp)

- [136. 只出现一次的数字 (easy)](https://leetcode.cn/problems/single-number/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/136singleNumber.cpp)


# 2.合并数组

- [88. 合并两个有序数组 (easy)](https://leetcode-cn.com/problems/merge-sorted-array/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/88merge.cpp)

# 3.保序filter

- [26. 删除有序数组中的重复项 (easy)](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/26removeDuplicates.cpp)

- [283. 移动零 (easy)](https://leetcode-cn.com/problems/move-zeroes/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/283moveZeroes.cpp)

# 4.前缀和&差分

```
前缀和:s[i]=sum(0,i)=sum(0,i-1)+a[i]
--> 做差分计算子段和:sum(l,r)=sum(0,r)-sum(0,l-1)

二维前缀和：s[i][j]=sum(a[x][y])(x<=i,y<=j)=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j]
--> 做差分计算以(p,q)为左上角、(i,j)为右下角的子矩阵和:sum(p,q,i,j)=s[i][j]-s[i][q-1]-s[p-1][j]+s[p-1][q-1]

差分:B[1]+B[2]+...+B[n]=(A[2]-A[1])+(A[3]-A[2])+...+(A[n]-A[n-1])=A[n]
--> 结论：差分数组B的前缀和，就是原数组A
--> 差分一般这样用：在计算给A的子段统一加一个数的时候，即A[l,r]+d，时间复杂度O(n)。但利用差分算，只要B[l]+d、B[r+1]-d，时间复杂度O(1)

前缀和的用法：求“子段和”（窗口求和）
用前缀和需满足区间减法性质，即[l,r]的信息，可以由[1,l]和[l,r]的信息推导出来

还有一种特殊的，是前缀max/前缀min
```

- [1248. 统计「优美子数组」 (median)](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/1248numberOfSubarrays.cpp)

- [53. 最大子数组和 (easy)](https://leetcode-cn.com/problems/maximum-subarray/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/53maxSubArray.cpp)

- [303. 区域和检索 - 数组不可变 (easy)](https://leetcode-cn.com/problems/range-sum-query-immutable/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/303NumArray.cpp)

- [304. 二维区域和检索 - 矩阵不可变 (median)](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/304NumMatrix.cpp)

- [1109. 航班预订统计 (median)](https://leetcode-cn.com/problems/corporate-flight-bookings/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/1109corpFlightBookings.cpp)

- [560. 和为 K 的子数组 (median)](https://leetcode-cn.com/problems/subarray-sum-equals-k/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/560subarraySum.cpp)

- [238. 除自身以外数组的乘积 (median)](https://leetcode.cn/problems/product-of-array-except-self/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/238productExceptSelf.cpp)



# 5.双指针扫描

```
用于解决基于“子段”的统计问题
朴素的做法是双重循环（for l...for r...)，优化的手法是尝试去除内层循环

优化策略有两种：
1.前缀和：固定右端点，看左端点的取值范围(0..l-1)
2.双指针扫描/单调队列：移动一个端点，看另一个端点的变动情况。如果同时递增，那就是个滑动窗口

双指针扫描的用法：解决子段问题。维护的信息是关于点的（比如接雨水的两个端点，twoSum的两个端点），跟中间无关的情况。
如果维护的信息是整个候选集合（多个点），那么用单调队列
```

- [167. 两数之和 II - 输入有序数组 (median)](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/167twoSum.cpp)

- [1. 两数之和 (easy)](https://leetcode.cn/problems/two-sum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/1twoSum.cpp)

- [15. 三数之和 (median)](https://leetcode-cn.com/problems/3sum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/15threeSum.cpp)

- [11. 盛最多水的容器 (median)](https://leetcode-cn.com/problems/container-with-most-water/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/11maxArea.cpp)

- [75. 颜色分类 (median)](https://leetcode-cn.com/problems/sort-colors/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/75sortColors.cpp)

- [76. 最小覆盖子串 (hard)](https://leetcode-cn.com/problems/minimum-window-substring/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/76minWindow.cpp)

- [287. 寻找重复数 (median)](https://leetcode-cn.com/problems/find-the-duplicate-number/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/01_数组/287findDuplicate.cpp)


