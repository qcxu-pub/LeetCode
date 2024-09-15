#include <string>
#include <vector>
using namespace std;

/*
66. 加一
https://leetcode-cn.com/problems/plus-one/

*/

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans_reverse;
        int flag = true;
        for (int i = n - 1; i >= 0; --i) {
            int digit = digits[i];
            if (digit == 9 && flag) {
                ans_reverse.push_back(0);
                flag = true;
            }
            else if (digit == 9 && !flag) {
                ans_reverse.push_back(digit);
                flag = false;
            }
            else if (digit != 9 && flag) {
                ans_reverse.push_back(digit + 1);
                flag = false;
            }
            else {
                ans_reverse.push_back(digit);
                flag = false;
            }
        }
        if (flag)
            ans_reverse.push_back(1);

        vector<int> ans;
        for (int i = ans_reverse.size() - 1; i >= 0; --i)
            ans.push_back(ans_reverse[i]);

        return ans;
    }
};