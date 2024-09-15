#include <string>
#include <vector>
using namespace std;

/*
151. 颠倒字符串中的单词
https://leetcode-cn.com/problems/reverse-words-in-a-string/

*/

class Solution {
   public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        s = s + " ";
        for (char& ch : s) {
            if (ch == ' ' && word == "")
                continue;
            else if (ch == ' ' && word != "") {
                words.push_back(word);
                word = "";
            } else
                word += ch;
        }

        // 倒序输出
        string ans = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            ans += words[i];
            if (i > 0)
                ans += " ";
        }
        return ans;
    }
};