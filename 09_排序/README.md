```
排序算法分类：
1.基于比较的排序（更常用）
通过比较大小来决定元素间的相对次序。所以这类算法的好坏取决于比较次数。时间复杂度最快是O(NlogN)
包括：
1.1 交换排序：冒泡排序，快速排序（sort函数默认）
1.2 插入排序：简单插入排序，希尔排序
1.3 选择排序：简单选择排序，堆排序
1.4 归并排序：二路归并排序，多路归并排序  --> 相当于分治

2.基于非比较类排序
不是通过比大小来决定元素的相对次序，而是通过分组、计数等手段排序。时间复杂度取决于元素范围、分布情况等，不单纯取决于元素的数量N
包括：
2.1 计数排序
2.2 桶排序
2.3 基数排序
```
```
排序的稳定性
对于序列中存在的若干个关键字相等的元素。如果排序前后他们的相对次序一定保持不变，则排序是稳定的。反之，则不稳定。
稳定序列都是基于序列挨个扫一遍，这样可以保证相同元素下标的前后顺序是不变的

稳定的排序：插入、冒泡、归并、计数、基数、桶排序
不稳定的排序：选择、希尔、快速、堆排序

不稳定的原因：
选择排序：这个位置要放什么，通过交换的方式换到当前位置。因为涉及到交换，所以就不稳定了
堆排序：两个都是最小值，小顶堆，pop出来哪个是随机的
```
```
总结
时间复杂度    稳定 ----------------------------------> 不稳定
O(n^2)      插入排序             冒泡排序             选择排序
???         计数排序/基数排序     桶排序               希尔排序
O(nlogn)    归并排序             堆排序               快速排序
```

# 1.基于比较的各类排序算法

```
1.选择排序(Selection Sort)：该放哪个数了？
每次从未排序数据中找最小值，交换到已排序序列的末尾。时间复杂度：O(N^2)
（代码见912题）
因为要求最小值，会想到用小根堆优化，就有了堆排序。时间复杂度：O(NlogN)
（代码见912题）

2.插入排序(Insertion Sort)：这个数该放哪儿？
从前到后依次考虑每个未排序的数据，在已排序序列中找到合适的位置插入。时间复杂度：O(N^2)
（代码见912题）
插入排序慢在插到哪里的过程。但如果本身相对比较有顺序，或者要排序的序列本身比较短，就会快很多。那就把数据分组，先小组排好序，然后大组。
希尔排序是对插入排序的优化，增量分组插入排序（不常用）。时间复杂度取决于步长的选取。
希尔排序具体的做法是：设置步长，开始步长大，这样每组中的元素少，比如10个数，5为步长，那就是两两之间的比较交换。然后缩小步长，每组中的元素变多。最后步长是1，每组元素就是全部元素

3.冒泡排序(Bubble Sort)
不断循环扫描，每次查看相邻元素，如果逆序，则交换。最后要满足，相邻都是顺序的。时间复杂度：O(N^2)
（代码见912题）

4.归并排序(Merge Sort)：基于分治的算法
原问题：把数组排序
子问题：把数组前一半、后一半分别排序。然后再合并两个有序数组
时间复杂度：遍历每一层是O(N)，每一层是O(logN)。所以总共O(NlogN)
（代码见912题）

5.快速排序(Quick Sort)：也是基于分治的算法
从数组中选取中轴元素pivot，将小元素放到pivot左边，大元素放到右边。然后分别对左边和右边的子数组进行快排
时间复杂度：期望是O(NlogN)，最坏是O(N^2)。所以要随机选取pivot
（代码见912题）

快速排序和归并排序具有相似性，但步骤相反：
归并排序：先排序左右子数组，然后合并两个有序数组
快速排序：先调配出左右子数组，然后对左右子数组分别进行排序

```

- [912. 排序数组 (median)](https://leetcode-cn.com/problems/sort-an-array/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/912sortArray.cpp)


# 2.基于非比较的各类排序算法

```
1.计数排序(Counting Sort)
要求输入的数据必须是有确定范围的整数，且范围不大，比如都是10w以内。
举个例子：
待排序的：[2,7,6,1,6,3]
需要额外空间数组：arr = [0,1,1,1,0,0,2,1], arr[num]=count
再把arr展平：[1,2,3,6,6,7]
时间复杂度：O(N+M)，N是元素个数，M是数值范围

2.桶排序(Bucket Sort) --了解即可
先分桶，然后桶内排序
举个例子：
待排序的：[231,123,125,213,321]
分组：（按百分位来）
1:[123,125]
2:[213,231]
3:[321]
然后桶内排序，排序规则可继续桶排序，也可以是快排等
时间复杂度：跟内部排序方式有关；跟分桶规则的数据分布有关，均匀分布就比较快了

3.基数排序(Radix Sort) --了解即可
从低位到高位，对每一位分别进行计数排序。要保持上一次的相对顺序。
举个例子：
待排序的：[231,123,125,213,321]
按个位排序：[231,321,123,213,125]
按十位排序：[213,321,123,125,231]
按百位排序：[123,125,213,231,321]
时间复杂度：O(NK)，K为数字位数
```


# 3.排序的应用


- [1122. 数组的相对排序 (easy)](https://leetcode-cn.com/problems/relative-sort-array/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/1122relativeSortArray.cpp)

- [56. 合并区间 (median)](https://leetcode-cn.com/problems/merge-intervals/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/56merge.cpp)

- [215. 数组中的第K个最大元素 (median)](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/215findKthLargest.cpp)

- [104. 货仓选址](www.acwing.com/problem/content/description/106/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/104findPosition.cpp)

- [493. 翻转对 (hard)](https://leetcode-cn.com/problems/reverse-pairs/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/493reversePairs.cpp)

- [剑指 Offer 51. 数组中的逆序对 (hard)](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/51reversePairs.cpp)

- [327. 区间和的个数 (hard)](https://leetcode-cn.com/problems/count-of-range-sum/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/327countRangeSum.cpp)

- [399. 螺丝和螺帽问题 (hard)](https://www.jiuzhang.com/solutions/nuts-bolts-problem/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/09_排序/399sortNutsAndBolts.cpp)
