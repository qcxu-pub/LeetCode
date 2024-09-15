#include <string>
#include <vector>
using namespace std;

/*
14. 最长公共前缀
https://leetcode-cn.com/problems/longest-common-prefix/

*/

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        string ans = strs[0];
        for (string str : strs) {
            int idx = 0;
            for (; idx < str.length() && idx < ans.length(); ++idx) {
                if (str[idx] != ans[idx])
                    break;
            }
            ans = ans.substr(0, idx);
            if (ans == "")
                return "";
        }
        return ans;
    }
};