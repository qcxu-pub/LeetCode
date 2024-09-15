#include <vector>
using namespace std;

/*
55. 跳跃游戏
https://leetcode-cn.com/problems/jump-game/

跟45题类似。只是目标变了
*/

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1e9);
        f[0] = 0;
        // 最后一个就是终点，不用遍历
        for (int i = 0; i < n - 1; ++i) {
            int step = nums[i];
            for (int s = 0; s <= step; ++s) {
                // 如果当前点不可到达，那就递推不下去了
                if (f[i] == 1e9)
                    return false;
                // 递推到终点了
                if (i + s >= n - 1)
                    return true;
                // 状态转移，往 f[i+s] 的格子跳跃 1 步
                else
                    f[i + s] = min(f[i + s], f[i] + 1);
            }
        }
        // case: [0]
        return f[n - 1] < 1e9;
    }
};