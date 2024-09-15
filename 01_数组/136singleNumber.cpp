#include <vector>
using namespace std;

/*
136. 只出现一次的数字
https://leetcode.cn/problems/single-number/

位运算 - 异或
1.a XOR 0 = a
2.a XOR a = 0
3.a XOR b XOR a = b XOR a XOR a = b XOR (a XOR a) = b XOR 0 = b
也就是说，出现两次的，经过XOR运算后，就变成0了。只出现一次的，经过XOR运算后会被保留。
所以把所有的数字全部XOR以后，就是答案

*/

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums)
            ans ^= num;
        return ans;
    }
};