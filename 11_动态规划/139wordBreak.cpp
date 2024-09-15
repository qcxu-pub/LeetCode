#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
139. 单词拆分
https://leetcode-cn.com/problems/word-break/

状态: f[l,r]表示s[l,r]区间字符串单词是否可拆分
状态转移:
1.s[l,r]在dct中直接能找着: f[l,r]=true
2.s[l,r]在dct中找不着，那就看能不能拆分着找着
f[l,r] |= (f[l,k]&&f[k+1,r]), k=l...r-1。 只要有一个k可以就为true

目标: f[0,n-1] / f[1,n]
*/

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // {length1:{word1,word2,...}, length2:{...}}
        unordered_map<int, unordered_set<string> > dct;
        for (string& word : wordDict) {
            int len = word.length();
            dct[len].insert(word);
        }

        int n = s.length();
        s = " " + s;

        vector<vector<bool> > f(n + 1, vector<bool>(n + 1, false));

        // for区间长度
        for (int len = 1; len <= n; ++len)
            // for左端点。len = r - l + 1
            for (int l = 1; l <= n - len + 1; ++l) {
                int r = l + len - 1;
                string str = s.substr(l, len);
                // 先看dct里面能不能找到
                if (dct.find(len) != dct.end() && dct[len].find(str) != dct[len].end()) {
                    f[l][r] = true;
                    continue;
                }
                // dct里面找不到，就看能不能拆解。是从区间更小的状态转移过来的
                // k=l:  [l][l+1,l+2,...,r]
                // k=r-1:[l,l+1,...,r-1][r]
                for (int k = l; k < r; ++k)
                    f[l][r] = f[l][r] || (f[l][k] && f[k + 1][r]);
            }
        return f[1][n];
    }
};
