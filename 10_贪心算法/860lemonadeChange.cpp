#include <vector>
#include <unordered_map>
using namespace std;

/*
860. 柠檬水找零
https://leetcode-cn.com/problems/lemonade-change/

本题给的面值满足决策包容性。就是说，如果能用1个10块，那用2个5块必然也可以
所以贪心就是优先使用较大面值找零
*/

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        coins[5] = 0, coins[10] = 0, coins[20] = 0;
        for (int bill : bills) {
            coins[bill]++;
            if (!exchange(bill - 5))
                return false;
        }
        return true;
    }

   private:
    unordered_map<int, int> coins;

    bool exchange(int amount) {
        for (int x : {20, 10, 5}) {
            while (amount >= x && coins[x] > 0) {
                coins[x]--;
                amount -= x;
            }
        }
        return amount == 0;
    }
};