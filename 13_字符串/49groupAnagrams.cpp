#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
49. 字母异位词分组
https://leetcode-cn.com/problems/group-anagrams/

哈希那章做过这道题。再来一遍。。
*/

class Solution {
   public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > groups;
        for (string& s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            if (groups.find(copy) == groups.end())
                groups[copy] = {s};
            else
                groups[copy].push_back(s);
        }

        vector<vector<string> > ans;
        for (auto group : groups) {
            ans.push_back(group.second);
        }
        return ans;
    }
};