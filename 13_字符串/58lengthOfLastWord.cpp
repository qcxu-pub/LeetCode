#include <string>
using namespace std;

/*
58. 最后一个单词的长度
https://leetcode-cn.com/problems/length-of-last-word/

*/

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        // 最后一个单词，所以想法是从后往前遍历
        for (int i = s.length() - 1; i >= 0; --i) {
            // 最后一个单词结束的地方
            if (ans == 0 && s[i] == ' ')
                continue;
            // 最后一个单词开始的地方
            else if (ans > 0 && s[i] == ' ')
                return ans;
            // 最后一个单词
            else
                ans += 1;
        }
        return ans;
    }
};