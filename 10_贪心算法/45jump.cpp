#include <vector>
using namespace std;

/*
45. 跳跃游戏 II
https://leetcode-cn.com/problems/jump-game-ii/

多往后看一步，走的一定是c1,c2,c3中最大的那个对应的b
a --> b1 --> c1
a --> b2 --> c2
a --> b3 --> c3

决策包容性：因为要去更远的地方，而且走的是多少步以内，所以更远的地方是包容的
*/

class Solution {
   public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int now = 0;
        // int tailIdx = num.size() - 1;
        while (now < nums.size() - 1) {
            if (now + nums[now] >= nums.size() - 1)
                return ans + 1;
                
            int next = now;
            int nextBegin = next + nums[next];
            // 跳跃 i 步，到 b=now+i 这个位置
            for (int i = 1; i <= nums[now]; ++i) {
                int nextStep = now + i;
                if (nextStep + nums[nextStep] > nextBegin) {
                    next = nextStep;
                    nextBegin = nextStep + nums[nextStep];
                }
            }
            now = next;
            ans += 1;
        }
        return ans;
    }
};