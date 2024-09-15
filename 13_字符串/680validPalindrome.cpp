#include <string>
using namespace std;

/*
680. 验证回文字符串 Ⅱ
https://leetcode-cn.com/problems/valid-palindrome-ii/

跟搜索有点像。要么删l，要么删r。只探一层，看剩余那段是否是回文
原问题: [0,n-1]可以删1次是否是回文
子问题: 删l，那[l+1,r]可以删0次是否是回文；删r，那[l,r-1]可以删0次是否是回文

状态: 左index，右index，剩余删除次数

*/

class Solution {
   public:
    bool validPalindrome(string s) {
        return check(s, 0, s.size() - 1, 1);
    }

   private:
    bool check(string& s, int l, int r, int times) {
        // 边界
        if (times < 0)
            return false;

        while (l < r) {
            if (s[l] != s[r])
                return check(s, l + 1, r, times - 1) || check(s, l, r - 1, times - 1);
            // s[l]==s[r]
            l++;
            r--;
        }
        return true;
    }
};