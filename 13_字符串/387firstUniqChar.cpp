#include <string>
#include <unordered_map>
using namespace std;

/*
387. 字符串中的第一个唯一字符
https://leetcode-cn.com/problems/first-unique-character-in-a-string/

*/

class Solution {
   public:
    int firstUniqChar(string s) {
        unordered_map<char, int> h;
        for (char ch : s) {
            h[ch] += 1;
        }

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (h[ch] == 1)
                return i;
        }
        return -1;
    }
};