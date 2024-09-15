#include <string>
#include <vector>
using namespace std;

/*
917. 仅仅反转字母
https://leetcode-cn.com/problems/reverse-only-letters/

*/

class Solution {
   public:
    string reverseOnlyLetters(string s) {
        vector<char> letters;
        for (char& ch : s) {
            if (isLetter(ch))
                letters.push_back(ch);
        }

        string ans = "";
        int sidx = 0;
        int vidx = letters.size() - 1;
        for (; sidx < s.length(); --vidx, ++sidx) {
            // 找到可以插字母的位置sidx
            while (!isLetter(s[sidx]) && sidx < s.length()) {
                ans += s[sidx];
                sidx++;
            }
            // 把reverse的字符插到当前位置
            if (vidx >= 0)
                ans += letters[vidx];
        }
        return ans;
    }

   private:
    bool isLetter(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
};