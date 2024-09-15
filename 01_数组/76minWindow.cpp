#include <limits.h>
#include <string>
#include <unordered_map>
using namespace std;

#include <iostream>

/*
76. 最小覆盖子串
https://leetcode-cn.com/problems/minimum-window-substring/

想法：右指针用来扩展，保证有所有字符；左指针用于收缩，保证最短
*/

class Solution {
   public:
    string minWindow(string s, string t) {
        for (char& ch : t)
            tmap[ch] += 1;

        int minLen = INT_MAX;
        int startIdx = -1;

        int l = 0, r = 0;
        // 扩展右指针
        while (r < s.length()) {
            if (tmap.find(s[r]) != tmap.end())
                wmap[s[r]] += 1;

            // 缩左指针
            while (t.length() > 0 && r - l >= t.length() - 1 && r >= l && isSame()) {
                if (r - l + 1 < minLen) {
                    minLen = min(minLen, r - l + 1);
                    startIdx = l;
                }
                if (tmap.find(s[l]) != tmap.end())
                    wmap[s[l]] -= 1;
                ++l;
            }
            ++r;
        }

        return startIdx == -1 ? string() : s.substr(startIdx, minLen);
    }

   private:
    unordered_map<char, int> tmap;
    unordered_map<char, int> wmap;

    bool isSame() {
        for (const auto& sp : tmap) {
            if (wmap[sp.first] < sp.second) {
                return false;
            }
        }
        return true;
    }
};