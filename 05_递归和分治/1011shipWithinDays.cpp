#include <vector>
using namespace std;

/*
1011. 在 D 天内送达包裹的能力
https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/

*/

class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int weight : weights) {
            left = max(left, weight);
            right += weight;
        }

        this->weights = weights;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(mid, days))
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }

   private:
    vector<int> weights;
    bool isValid(int capacity, int days) {
        int usedDays = 1;
        int accumWeight = 0;
        for (int weight : weights) {
            if (accumWeight + weight <= capacity)
                accumWeight += weight;
            else {
                usedDays += 1;
                accumWeight = weight;  // 第一个的重量要加进去
            }
        }
        return usedDays <= days;
    }
};