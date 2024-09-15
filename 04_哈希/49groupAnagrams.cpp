#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
49. 字母异位词分组
https://leetcode-cn.com/problems/group-anagrams/

思路：
分组与hash具有相似性：{"abc":["abc","bac","cab"],"efg":["feg","gef"],...}
*/

class Solution {
   public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        for (string& s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            if (groups.find(copy) == groups.end())
                groups[copy] = {s};
            else
                groups[copy].push_back(s);
        }
        vector<vector<string> > ans;
        // map -> vector
        for (const pair<string, vector<string> >& group : groups) {
            ans.push_back(group.second);
        }
        return ans;
    }

   private:
    unordered_map<string, vector<string> > groups;
};