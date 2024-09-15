#include <string>
using namespace std;

/*
709. 转换成小写字母
https://leetcode-cn.com/problems/to-lower-case/

*/

class Solution {
   public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        }
        return s;
    }
};