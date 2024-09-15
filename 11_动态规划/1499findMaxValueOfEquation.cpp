#include <vector>
#include <deque>
using namespace std;

/*
1499. 满足不等式的最大值
https://leetcode-cn.com/problems/max-value-of-equation/

比刚才的引入的例子多了一个条件: |xi - xj| <= k 的前提下，求 yi + yj + |xi - xj| 的最大值
i和j还是没有顺序的，所以设 xj < xi 时，那么 xj 在 xi 左边不能太远，具体就是，xi-k <= xj < xi
所以，当 xi 增大时，xj 的上界和下界都是增大的（跟刚才比，这个下界也在增长）
要求的最大值，固定i，那么我们要维护的是，yj-xj 的max

如果j只有上界增长，那这个问题是前缀max
那j上下界同时变化，那问题的就是滑动窗口。所以这题的本质，就是求滑动窗口最大值！
滑动窗口用单调队列求解，队头是最优值
要求的是窗口最大值，所以小的值在窗口前面就永无出头之日了，所以这个单调队列是递减的，即: 
if j1 <= j2, y[j1]-x[j1] >= y[j2] - x[j2]
*/

class Solution {
   public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1e9;
        deque<int> q;

        // 相当于把外部循环固定了，也就是 xi+yi 是固定的。循环里面只要考虑 yj-xj
        for (int i = 0; i < points.size(); ++i) {

            // 方便看。但得写在条件里面。不然pop完了，front又变了。。。
            // int j = q.front();  // i>j
            // int xi = points[i][0];
            // int yi = points[i][1];
            // int xj = points[j][0];
            // int yj = points[j][1];

            // 窗口前面的元素j过期，过期条件 xj < xi - k
            while (!q.empty() && points[q.front()][0] < points[i][0] - k)
                q.pop_front();
            // 取队头作为窗口最优解 yi + xi + yj - xj
            if (!q.empty())
                ans = max(ans, points[i][1] + points[i][0] + points[q.front()][1] - points[q.front()][0]);
            // 维护单调队列单调性，yj-xj递增，跟新元素yi-xi比
            // j = q.back(), y[i]-x[i] > y[j] - x[j] --> y[j]-x[j] 永无出头之日，就pop掉队尾
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] < points[i][1] - points[i][0]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans;
    }
};