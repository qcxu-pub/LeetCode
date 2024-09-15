#include <string>
#include <unordered_map>
using namespace std;

/*
242. 有效的字母异位词
https://leetcode-cn.com/problems/valid-anagram/

哈希那章做过这道题。再来一遍。。
*/

class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map = getMap(s);
        unordered_map<char, int> t_map = getMap(t);
        return isEqual(s_map, t_map);
    }

   private:
    unordered_map<char, int> getMap(string s) {
        unordered_map<char, int> ans;
        for (char ch : s)
            ans[ch] += 1;
        return ans;
    }

    bool isEqual(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
        for (auto kv : map1) {
            char k = kv.first;
            int v = kv.second;
            if (map2.find(k) == map2.end() || v != map2[k])
                return false;
        }
        for (auto kv : map2) {
            char k = kv.first;
            int v = kv.second;
            if (map1.find(k) == map1.end() || map1[k] != v)
                return false;
        }
        return true;
    }
};