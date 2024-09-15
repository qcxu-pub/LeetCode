#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
438. 找到字符串中所有字母异位词
https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/

*/


/*
直接sort，超时了
*/

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.length();
        if (s.length() < len)
            return {};

        // p
        sort(p.begin(), p.end());
        // s
        vector<int> ans;
        // len = right - left + 1, right = s.length()
        for (int i = 0; i < s.length() - len + 1; ++i) {
            string sub = s.substr(i, len);
            sort(sub.begin(), sub.end());
            if (sub == p)
                ans.push_back(i);
        }
        return ans;
    }
};



/*
还是用hash吧
居然还是超时了。。
*/

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.length();
        if (s.length() < len)
            return {};

        hp = getMap(p);

        vector<int> ans;
        for (int i = 0; i < s.length() - len + 1; ++i) {
            string sub = s.substr(i, len);
            hs = getMap(sub);
            if (isEqual(hp, hs))
                ans.push_back(i);
        }
        return ans;
    }

   private:
    unordered_map<char, int> hp;
    unordered_map<char, int> hs;

    unordered_map<char, int> getMap(string s) {
        unordered_map<char, int> ans;
        for (char ch : s) {
            ans[ch] += 1;
        }
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


/*
用滑动窗口
能过
*/

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        if (sLen < pLen)
            return {};

        vector<int> pcnt(26, 0);
        vector<int> scnt(26, 0);
        vector<int> ans;

        // 前pLen个单独处理
        for (int i = 0; i < pLen; ++i) {
            pcnt[p[i] - 'a']++;
            scnt[s[i] - 'a']++;
        }
        if (pcnt == scnt)
            ans.push_back(0);
        
        // 长度为pLen的for循环处理
        for (int i = 0; i < sLen - pLen; ++i) {
            scnt[s[i] - 'a']--;
            scnt[s[i + pLen] - 'a']++;
            // [i+1,i+pLen]
            if (scnt == pcnt)
                ans.push_back(i + 1);
        }
        return ans;
    }
};