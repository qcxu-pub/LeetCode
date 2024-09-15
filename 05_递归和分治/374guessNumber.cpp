#include "stdlib.h"
/*
374. 猜数字大小
https://leetcode-cn.com/problems/guess-number-higher-or-lower/

求解的是：猜数问题。判定：大了还是小了。
二分查找更为高效。
*/

class Solution {
   public:
    int guessNumber(int n) {
        int left = 0, right = n;
        // answer = rand() * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

   private:
    int answer;

    // Forward declaration of guess API.
    bool guess(int num) {
        if (num < answer)
            return -1;
        else if (num == answer)
            return 0;
        else
            return 1;
    }
};