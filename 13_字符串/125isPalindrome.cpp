#include <string>
using namespace std;

/*
125. 验证回文串
https://leetcode-cn.com/problems/valid-palindrome/

双指针法

*/

/*用了O(n)的空间*/
class Solution {
   public:
    bool isPalindrome(string s) {
        string t;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9')
                t.push_back(ch);
            else if (ch >= 'a' && ch <= 'z')
                t.push_back(ch);
            else if (ch >= 'A' && ch <= 'Z')
                t.push_back(ch - 'A' + 'a');
        }

        int l = 0, r = t.size() - 1;
        while (l < r) {
            if (t[l] != t[r])
                return false;
            ++l, --r;
        }
        return true;
    }
};


/*用了O(1)的空间*/

class Solution {
   public:
    bool isPalindrome(string s) {
        int l = getNext(s, 0);
        int r = getPre(s, s.size() - 1);
        while (l < r) {
            if (!isEqual(s[l], s[r]))
                return false;
            l = getNext(s, l + 1);
            r = getPre(s, r - 1);
        }
        return true;
    }

   private:
    bool isDigitOrLetter(char ch) {
        if (ch >= '0' && ch <= '9')
            return true;
        if (ch >= 'A' && ch <= 'Z')
            return true;
        if (ch >= 'a' && ch <= 'z')
            return true;
        return false;
    }

    // 返回的是index
    int getNext(string& s, int i) {
        // 注意要先判断index合理性
        while (i < s.size() && !isDigitOrLetter(s[i]))
            ++i;
        return i;
    }

    int getPre(string& s, int i) {
        while (i >= 0 && !isDigitOrLetter(s[i]))
            --i;
        return i;
    }

    bool isEqual(char ch1, char ch2) {
        if (ch1 >= 'A' && ch1 <= 'Z')
            ch1 = ch1 - 'A' + 'a';
        if (ch2 >= 'A' && ch2 <= 'Z')
            ch2 = ch2 - 'A' + 'a';
        return ch1 == ch2;
    }
};