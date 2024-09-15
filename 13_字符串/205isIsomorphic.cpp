#include <string>
#include <unordered_map>
using namespace std;

/*
205. 同构字符串
https://leetcode-cn.com/problems/isomorphic-strings/

*/

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> h1;
        unordered_map<char, char> h2;

        if (s.length() != t.length())
            return false;

        int n = s.length();
        for (int i = 0; i < n; ++i) {
            char chs = s[i];
            char cht = t[i];
            if (h1.find(chs) == h1.end() && h2.find(cht) == h2.end()) {
                h1[chs] = cht;
                h2[cht] = chs;
            } else if (h1[chs] != cht || h2[cht] != chs)
                return false;
        }
        return true;
    }
};