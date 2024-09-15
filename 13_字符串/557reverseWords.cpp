#include <string>
using namespace std;

/*
557. 反转字符串中的单词 III
https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

*/

class Solution {
   public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        // 尾部加个空格，是因为想把最后一个单词的逻辑放到for循环里面
        // 但是，因为reverse是在原字符串上操作的，所以最后答案长度要-1
        s = s + " ";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                r = i - 1;
                reverse(s, l, r);
                l = i + 1;
            }
        }
        return s.substr(0, s.length() - 1);
    }

   private:
    void swap(string& s, int i, int j) {
        int t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    void reverse(string& s, int start, int end) {
        for (; start < end; ++start, --end) {
            swap(s, start, end);
        }
    }
};