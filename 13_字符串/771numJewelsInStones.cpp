#include <string>
#include <unordered_set>
using namespace std;

/*
771. 宝石与石头
https://leetcode-cn.com/problems/jewels-and-stones/

*/

class Solution {
   public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> h;
        for (char ch : jewels)
            h.insert(ch);

        int ans = 0;
        for (char ch : stones) {
            if (h.find(ch) != h.end())
                ans++;
        }
        return ans;
    }
};