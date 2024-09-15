#include <vector>
using namespace std;

/*
55. 跳跃游戏
https://leetcode-cn.com/problems/jump-game/

跟45题很像
*/

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int curr = 0;
        while (curr < nums.size() - 1) {
            if (curr + nums[curr] >= nums.size() - 1)
                return true;

            int next = curr;
            int nextBegin = next + nums[next];
            for (int i = 1; i <= nums[curr]; ++i) {
                int nextStep = curr + i;
                if (nextStep + nums[nextStep] > nextBegin) {
                    next = nextStep;
                    nextBegin = nextStep + nums[nextStep];
                }
            }
            // 得先判断，不能先更新curr。。
            if (nextBegin <= curr + nums[curr])
                return false;
            // 跳一步
            curr = next;
        }
        return true;  // 只有一个元素的，不会进入while语句，会走到这里
    }
};