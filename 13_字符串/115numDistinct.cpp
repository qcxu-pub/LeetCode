#include <string>
#include <vector>
#include "limits.h"
using namespace std;

/*
115. 不同的子序列
https://leetcode-cn.com/problems/distinct-subsequences/

找子问题
s="rabbbit", t="rabbit"
子问题就是: s="rabbb", t="rabb" 的不同子序列

状态: f[i,j]表示，s[1~i]选子序列得到t[1~j]的方案数
状态转移:
1.如果s[i]=s[j]，要s[i]: f[i,j] = f[i-1,j-1]
2.不要s[i]: f[i,j] = f[i-1,j]
初始值:
f[i,0] = 1，就是把s删光有一种方案
目标: f[n,m]
*/

class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        s = " " + s;
        t = " " + t;

        vector<vector<int> > f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            f[i][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // 不选
                f[i][j] = f[i - 1][j];
                // 选。只有 s[i] == t[j] 的时候才可以
                // f[i][j] + f[i - 1][j - 1]会INT溢出，所以移项处理
                if (s[i] == t[j] && f[i][j] <= INT_MAX - f[i - 1][j - 1])
                    f[i][j] += f[i - 1][j - 1];
            }
        }
        return f[n][m];
    }
};