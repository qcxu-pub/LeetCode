#include <string>
using namespace std;

/*
415. 字符串相加
https://leetcode-cn.com/problems/add-strings/

这题可以看看 char 跟 int 的转换
*/

class Solution {
   public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string reverse = "";
        int upperAdd = 0;

        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0) {
            int sum = 0;
            if (i < 0)
                sum = (num2[j] - '0') + upperAdd;
            else if (j < 0)
                sum = (num1[i] - '0') + upperAdd;
            else
                sum = (num1[i] - '0') + (num2[j] - '0') + upperAdd;

            reverse.push_back((sum % 10) + '0');
            upperAdd = sum / 10;

            --i, --j;
        }

        while (upperAdd > 0) {
            reverse.push_back((upperAdd % 10) + '0');
            upperAdd /= 10;
        }

        // 把顺序颠过来
        string ans = "";
        for (int i = reverse.length() - 1; i >= 0; --i)
            ans.push_back(reverse[i]);
        return ans;
    }
};