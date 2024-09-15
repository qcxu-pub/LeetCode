#include <string>
#include <vector>
using namespace std;

/*
516. 最长回文子序列
https://leetcode-cn.com/problems/longest-palindromic-subsequence/

状态: f[l,r]表示在[l,r]之间的最长回文子序列长度
状态转移:
    if s[l]==s[r]: f[l,r] = f[l+1,r-1] + 2
    if s[l]!=s[r]: f[l,r] = max(f[l+1,r], f[l,r-1])
    发现都是从区间更短的，转移到区间更长的。所以可以用区间动态规划
目标: f[0,n-1]
*/

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> > f(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        // for区间
        for (int len = 2; len <= n; ++len) {
            // for左端点。len = r - l + 1
            for (int l = 0; l < n - len + 1; ++l) {
                int r = l + len - 1;
                if (s[l] == s[r])
                    f[l][r] = f[l + 1][r - 1] + 2;
                else
                    f[l][r] = max(f[l + 1][r], f[l][r - 1]);
            }
        }
        return f[0][n - 1];
    }
};