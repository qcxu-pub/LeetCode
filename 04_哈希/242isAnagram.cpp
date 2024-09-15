#include <string>
#include <unordered_map>
using namespace std;

/*
242. 有效的字母异位词
https://leetcode-cn.com/problems/valid-anagram/

思路：
利用 hashmap 给字符计数，两个字符串对应的 hashmap 是否相同
*/

class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map = getMap(s);
        unordered_map<char, int> t_map = getMap(t);
        return isEqualMap(s_map, t_map);
    }

   private:
    unordered_map<char, int> getMap(string& str) {
        unordered_map<char, int> ans;
        for (char ch : str)
            ans[ch] += 1;
        return ans;
    }
    bool isEqualMap(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
        for (auto& kv : map1) {
            char k = kv.first;
            int v = kv.second;
            if (map2.find(k) == map2.end() || map2[k] != v)
                return false;
        }
        for (auto& kv : map2) {
            char k = kv.first;
            int v = kv.second;
            if (map1.find(k) == map1.end() || map1[k] != v)
                return false;
        }
        return true;
    }
};