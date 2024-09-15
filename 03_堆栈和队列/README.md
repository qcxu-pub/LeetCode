# 1.栈stack/队列queue/双端队列deque基本题目

- [155. 最小栈 (easy)](https://leetcode-cn.com/problems/min-stack/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/155MinStack.cpp)

- [20. 有效的括号 (easy)](https://leetcode-cn.com/problems/valid-parentheses/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/20isValid.cpp)

- [641. 设计循环双端队列 (median)](https://leetcode-cn.com/problems/design-circular-deque/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/641MyCircularDeque.cpp)

- [232. 用栈实现队列 (easy)](https://leetcode-cn.com/problems/implement-queue-using-stacks/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/232MyQueue.cpp)

- [225. 用队列实现栈 (easy)](https://leetcode-cn.com/problems/implement-stack-using-queues/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/225MyStack.cpp)

- [844. 比较含退格的字符串 (easy)](https://leetcode-cn.com/problems/backspace-string-compare/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/844backspaceCompare.cpp)


# 2.栈的应用：表达式求值系列问题

- [150. 逆波兰表达式求值 (median)](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/150evalRPN.cpp)

- [227. 基本计算器 II (median)](https://leetcode-cn.com/problems/basic-calculator-ii/) / [224. 基本计算器 (hard)](https://leetcode-cn.com/problems/basic-calculator/)| [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/224calculate.cpp)


# 3.堆的应用：优先队列priority_queue

```
原理：完全二叉树。最多只有2个子结点，只能是最后一层的右边缺结点。所以，如果用数组存放该结构，则：
1.如果根节点索引为1，则索引为p的结点，左孩子索引p*2，右孩子索引p*2+1；索引为p的结点，父节点索引p/2向下取整
2.如果根节点索引为0，则索引为p的结点，左孩子索引p*2+1，右孩子索引p*2+2；索引为p的结点，父节点索引(p-1)/2向下取整
（以根节点索引为1开始更好记一点）

priority_queue 是二叉堆的应用。
大顶堆：根结点最大的堆。左右兄弟结点的大小无所谓。
小顶堆：根结点最小的堆
默认的比较函数是<，即大顶堆
```

- [23. 合并K个升序链表 (hard)](https://leetcode.cn/problems/merge-k-sorted-lists/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/23mergeKLists.cpp)

- [239. 滑动窗口最大值 (hard)](https://leetcode.cn/problems/sliding-window-maximum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/239maxSlidingWindow.cpp)

- [703. 数据流中的第 K 大元素 (easy)](https://leetcode.cn/problems/kth-largest-element-in-a-stream/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/703KthLargest.cpp)

- [215. 数组中的第K个最大元素 (median)](https://leetcode.cn/problems/kth-largest-element-in-an-array/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/215findKthLargest.cpp)

- [973. 最接近原点的 K 个点 (median)](https://leetcode.cn/problems/k-closest-points-to-origin/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/973kClosest.cpp)

- [347. 前 K 个高频元素 (median)](https://leetcode.cn/problems/top-k-frequent-elements/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/347topKFrequent.cpp)

# 4.单调栈

```
确定递增递减-->前面不能影响后面的条件

for 每个元素
    while(栈顶与新元素不满足单调性) {
        弹栈
        更新答案
        累积宽度
    }
    入栈（新元素+累积宽度）
```

- [84. 柱状图中最大的矩形 (hard)](https://leetcode.cn/problems/largest-rectangle-in-histogram/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/84largestRectangleArea.cpp)

- [42. 接雨水 (hard)](https://leetcode.cn/problems/trapping-rain-water/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/42trap.cpp)

- [85. 最大矩形 (hard)-todo](https://leetcode.cn/problems/maximal-rectangle/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/85maximalRectangle.cpp)


# 5.单调队列

```
单调队列维护的是一个候选集合，具有时间单调性（下标i递增）
候选项的某个属性具有单调性（a[i] 递增或递减）--> 队头始终放最优值
确定递增递减，就是考虑 a[i],a[j] 更优的条件 (i<j)

for 每个元素:
    1.while(队头过期)
        队头出队
    2.取队头更新答案
    3.while(不满足单调性)
        队尾出队
      新元素入队
（2,3可对换，取决于i是否为候选项）
```

- [239. 滑动窗口最大值 (hard)](https://leetcode.cn/problems/sliding-window-maximum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/03_堆栈和队列/239maxSlidingWindow.cpp)

