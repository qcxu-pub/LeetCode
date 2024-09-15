#include <vector>
using namespace std;

/*
875. 爱吃香蕉的珂珂
https://leetcode.cn/problems/koko-eating-bananas/

*/

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1;
        for (int pile : piles) {
            right = max(right, pile);
        }

        this->piles = piles;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(mid, h))
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }

   private:
    vector<int> piles;

    bool isValid(int v, int h) {
        int usedH = 0;
        for (int pile : piles) {
            int x = (pile + v - 1) / v;  // 向上取整
            usedH += x;
        }
        return usedH <= h;
    }
};