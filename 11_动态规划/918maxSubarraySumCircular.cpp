#include <vector>
#include <queue>
using namespace std;

/*
918. 环形子数组的最大和
https://leetcode-cn.com/problems/maximum-sum-circular-subarray/

同样是通过分离状态、决策变量，分离外层内层循环，优化动态转移
这还是一道环形动态规划，有处理环的技巧

先不考虑环。线性子段和的做法。
朴素: for i, for j, max{s[i]-s[j]}
优化为前缀和: 固定i，求F[i]=s[i]-min{s[j]}。F[i]就是以i为结尾的最大子段和。最终目标: max{F[i]}
前缀和其实不是严格意义上的动规。但是可以把i看做状态，把j看做决策，类似于一个动态状态转移方程
把状态和决策分离。把外层循环i和内层循环j分离。固定i看j的决策候选集合，就是前缀和

来考虑环。把数组看做线性[1,n]，然后复制一倍接在后面，变成长度为2n的数组
F[i]=s[i]-min{s[j]} -->求前缀和min，且带窗口
滑动窗口最小值! 窗口大小为n
滑动窗口用单调队列解决
*/

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        // 前缀和
        vector<int> s(2 * n + 1, 0);
        s[0] = 0;
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + nums[i];
        for (int i = n + 1; i <= 2 * n; ++i)
            s[i] = s[i - 1] + nums[i - n];

        // 固定i，在 i-n <= j <= i-1 这个区间里面，找滑动窗口里的最小值
        int ans = -1e9;
        deque<int> q;
        for (int i = 1; i <= 2 * n; ++i) {
            // 过期的出队
            while (!q.empty() && q.front() < i - n)
                q.pop_front();
            // 队头就是答案
            if (!q.empty())
                ans = max(ans, s[i] - s[q.front()]);
            // 维护单调队列，求的是最小值，所以滑动窗口应该是单调递增的
            while (!q.empty() && s[q.back()] >= s[i])
                q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};


/*
解法二：怎么解决环的问题
跟动规没啥关系
1.当最大子序和不跨越 1-n 的情况
  那直接按照线性数组做
2.当最大子序和跨越了1-n
  等价于开头取一段，结尾取一段，要和最大
  等价于 总和 - 中间取一段（和最小），即 total_sum - 按线性数组求最小子序和
最终目标: max(数组的最大子序和, total - 数组的最小子序和)
*/

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // 前缀和
        vector<int> s(n + 1, 0);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i];
        }

        // 1.当最大子序和不跨越 [1,n] 的情况, s[i]-min{f[j]}。线性上求解
        int temp = 1e9;
        int ansMax = -1e9;
        for (int i = 1; i <= n; ++i) {
            temp = min(temp, s[i - 1]);
            ansMax = max(ansMax, s[i] - temp);
        }

        // 2.当最大子序和跨越了[1,n] 的情况，totalSum - 最小字段和 = totalSum - min{f[i]-max{f[j]}}
        // 转化为线性上求解
        temp = -1e9;
        int ansMin = 1e9;
        // 跨越首个元素。子段和不包含首个元素
        for (int i = 2; i <= n; ++i) {
            temp = max(temp, s[i - 1]);
            ansMin = min(ansMin, s[i] - temp);
        }

        temp = -1e9;
        // 跨越尾部元素。子段和不包含尾部元素
        for (int i = 1; i < n; ++i) {
            temp = max(temp, s[i - 1]);
            ansMin = min(ansMin, s[i] - temp);
        }

        return max(ansMax, s[n] - ansMin);
    }
};