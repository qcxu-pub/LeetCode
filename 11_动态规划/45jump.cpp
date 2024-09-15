#include <vector>
using namespace std;

/*
45. 跳跃游戏 II
https://leetcode-cn.com/problems/jump-game-ii/

之前拿贪心做过，现在拿动规做

状态: f[i] 表示跳跃到 i 这个结点的时候，所用的最少跳跃次数
最优子结构: 到某个点的最小次数
状态转移: 怎么跳。从第i格跳到第i+s格。f[i+s] = min(f[i+s], f[i]+1), 其中, s <= nums[i]
目标: f[n-1]
*/

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1e9);
        f[0] = 0;
        // 从第i个点往后跳。最后一个是终点，可以不用遍历
        for (int i = 0; i < n - 1; ++i) {
            int step = nums[i];
            // 跳的步数 [1,step]
            for (int s = 1; s <= step; ++s) {
                // 跳到终点了
                if (i + s >= n)
                    f[n - 1] = min(f[n - 1], f[i] + 1);
                else
                    f[i + s] = min(f[i + s], f[i] + 1);
            }
        }
        return f[n - 1];
    }
};