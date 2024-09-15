#include <vector>
#include <algorithm>
using namespace std;

/*
1665. 完成所有任务的最少初始能量
https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks/

全排列，时间复杂度 n!，太慢了。试试贪心
门槛(minimun)高的要先做，花费(actual)小的要先做
直观感觉，按 actual - minimum 升序排序？

假设要排序的是 任务p 和 任务q
(min=minimum是门槛，a=actual是花费，所需的初始能量=max(本段门槛,本段花费+下一段的最小初始能量))

(1)如果先做 任务p

--------- | ----------------- | ----------------------- | --------------------
        min[p]    a[p]      min[q]      a[q]            s

此时所需的初始能量是:
max(minimum[p], actual[p] + max(minimum[q], actual[q]+s))
= max(minimum[p], minimum[q] + actual[p], actual[p] + actual[q] + s)

(2)如果先做 任务q

--------- | ----------------- | ----------------------- | --------------------
        min[q]    a[q]      min[p]      a[p]            s

此时所需的初始能量是:
max(minimum[q], actual[q] + max(minimum[p], actual[p]+s))
= max(minimum[q], minimum[p] + actual[q], actual[q] + actual[p] + s)

然后取(1)(2)中更小的情况。也就是说，如果要先做 任务p ，那么要满足:
max(minimum[p], minimum[q] + actual[p]) < max(minimum[q], minimum[p] + actual[q])

由于 minimum[q] + actual[p] > minimum[q] 恒成立，还有一对同理
所以，如果右项的最大值是 minimum[q]，那 < 不可能成立；如果右项的最大值是 minimum[p] + actual[q]，那 minimum[q] 就没什么用
所以，上面的不等式等价于:
minimum[q] + actual[p] < minimum[p] + actual[q]
即:
actual[p] - minimum[p] < actual[q] - minimum[q]  --> 这种情况下，先做任务p

所以，贪心的策略就是，按照 actual - minimum 升序排序，以此顺序完成任务
*/

class Solution {
   public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // lambda 表达式排序, tasks[i] = {actual[i], minimum[i]}
        sort(tasks.begin(), tasks.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[0] - a[1] < b[0] - b[1];
             });

        int ans = 0;
        for (int i = tasks.size() - 1; i >= 0; --i) {
            vector<int> task = tasks[i];
            ans = max(task[1], ans + task[0]);
        }
        return ans;
    }
};