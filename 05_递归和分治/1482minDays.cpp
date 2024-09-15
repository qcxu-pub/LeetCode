#include <vector>
using namespace std;

/*
1482. 制作 m 束花所需的最少天数
https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/

最小值，解很难。但看示例，给定盛开情况，问能不能制作m束花，用相邻的k朵，这就是是否合法的判定问题，很容易。
那就看，解是否单调。当然单调！当天数太少，花开的不够多的时候，就是不可行的；但天数多了，就能制作花了，就都可行了
求的是天数的最小值。就是上面的单调函数从false到true的分界点
*/

class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxDay = 0;
        for (int& bloom : bloomDay) {
            maxDay = max(maxDay, bloom);  // 某一天花全部都盛开了，这就是答案的最大值
        }

        int left = 0, right = maxDay + 1;  // right要考虑无解的情况
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (validate(bloomDay, m, k, mid)) {
                right = mid;  // 因为要求的是最小值
            } else {
                left = mid + 1;
            }
        }

        if (right == maxDay + 1)
            return -1;
        else
            return right;
    }

   private:
    bool validate(vector<int>& bloomDay, int m, int k, int now) {
        int bouquet = 0;      // 已经能做几束花了
        int continuous = 0;  // 现在累积有几朵了
        for (int& bloom : bloomDay) {
            if (bloom <= now) {
                // 花已盛开
                continuous += 1;
                if (continuous == k) {
                    // 累积到k朵花了，可以做一束了
                    bouquet += 1;
                    continuous = 0;
                }
            } else {
                // 当前花没盛开，就会打断连续
                continuous = 0;
            }
        }
        return bouquet >= m;
    }
};