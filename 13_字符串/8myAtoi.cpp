#include <string>
#include "limits.h"
using namespace std;

/*
8. 字符串转换整数 (atoi)
https://leetcode-cn.com/problems/string-to-integer-atoi/

题目怎么说，就怎么做

拓展
1.带小数点
2.带科学记数法，如: 1e9
*/

class Solution {
   public:
    int myAtoi(string s) {
        int n = s.length();
        int index = 0;
        // 1.弃用无用前导空格
        while (index < n && s[index] == ' ')
            ++index;

        // 2.正负号
        int sign = 1;
        if (index < n && (s[index] == '+' || s[index] == '-')) {
            sign = s[index] == '+' ? 1 : -1;
            index++;
        }
        
        // 3.处理数字知道非数字或结尾。越界截断
        int val = 0;
        while (index < n && s[index] >= '0' && s[index] <= '9') {
            int num = s[index] - '0';

            // 越界: val * 10 + (s[index] - '0') > 2^31-1 || <-2^31
            // 这个本身超过int范围。所以要不val改long long，要不等式移项
            if (val > (INT_MAX - num) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            val = val * 10 + num;
            index++;
        }
        return sign * val;
    }
};