#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#include <iostream>

/*
30. 串联所有单词的子串
https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/

思路：
1.子串与words串中的单词完全匹配：说明子串的长度固定，滑动窗口
2.子串与words串中单词是否匹配？两种思路：words串的排列组合，结果很多；子串拆解，结果唯一
3.子串拆解，会生成vector，words串也是vector。两个vector中所含元素是否相同？
  两种思路：vector
sort，字符串排序耗时；用hashmap，key是word，value是word出现次数，比较两个map是否相同（模板）
4.加速：以 k=len(word) 为滑动步长，共 k-1
组。这样子串拆解可以复用之前的map，没必要每次都新建一个
*/

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int totlen = 0;
        for(string& word: words) {
            totlen += word.length();
            map_words[word]++;
        }
        
        vector<int> ans;
        for (int i = 0; i + totlen <= s.length(); ++i) {

            string sub = s.substr(i, totlen);
            // cout << endl << "sub = " << sub << "-------";

            int sublen = words[0].length();
            unordered_map<string, int> map_split_words;
            for (int j = 0; j + sublen <= sub.length(); j += sublen) {
                // cout << sub.substr(j, sublen) << ",";
                map_split_words[sub.substr(j, sublen)]++;
            }
                

            if (isEqualMap(map_words, map_split_words))
                ans.push_back(i);
        }
        return ans;
    }

   private:
    unordered_map<string, int> map_words;

    bool isEqualMap(unordered_map<string, int>& map1, unordered_map<string, int>& map2) {
        for (auto& kv : map1) {
            string k = kv.first;
            int v = kv.second;
            if (map2.find(k) == map2.end() || map2[k] != v)
                return false;
        }
        for (auto& kv : map2) {
            string k = kv.first;
            int v = kv.second;
            if (map1.find(k) == map1.end() || map1[k] != v)
                return false;
        }
        return true;
    }
};