#include <string>
#include <vector>
using namespace std;

/*
44. 通配符匹配
https://leetcode-cn.com/problems/wildcard-matching/

状态f[i,j]表示s的前i个字符，和p的前j个字符，是否可以匹配

状态转移
1.p[j] == a~z
f[i,j] = f[i-1,j-1] if s[i]==p[j]
       = false      if s[i]!=p[j]

2.p[j] == ?
f[i,j] = f[i-1,j-1]

3.p[j] == *
p[j-1]==*: f[i,j]=f[i,j-1]
s[i]不包进*: f[i,j]=f[i,j-1]
s[i]包进*: f[i,j]=f[i-1,j-1] --> f[i-2,j-1] --> f[i-3,j-1] --> 路径上只要有一个为true，f[i,j]就可以为true
           就是说，s[i]不停地包进*，直至前缀s[i-k]跟s[j-1]一致，那这个状态就是true

初始值:
f[0,0]=true
f[i,k]=true if p[k]==* (k<=x) -- 开始的所有*，这个子段可以匹配任意字符串


目标: f[n,m]
*/

class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        s = " " + s;
        p = " " + p;

        vector<vector<int> > f(n + 1, vector<int>(m + 1, false));
        f[0][0] = true;
        for (int j = 1; j <= m; ++j) {
            if (p[j] == '*') {
                for (int i = 0; i <= n; ++i)
                    f[i][j] = true;
            } else {
                break;
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // cout << "i=" << i << ",j=" << j << ",s[i]=" << s[i] << ",p[j]=" << p[j] << " --- ";
                if (p[j] >= 'a' && p[j] <= 'z' && s[i] == p[j]) {
                    // cout << "case1";
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j] >= 'a' && p[j] <= 'z' && s[i] != p[j]) {
                    // cout << "case2";
                    f[i][j] = false;
                } else if (p[j] == '?') {
                    // cout << "case3";
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j] == '*') {
                    // cout << "case4";

                    // 不包
                    f[i][j] = f[i][j - 1];
                    if (p[j - 1] == '*') {
                        // cout << " --- " << f[i][j] << endl;
                        continue;
                    }
                    // 包
                    for (int k = i - 1; k >= 0 && !f[i][j]; --k)
                        f[i][j] = f[i][j] || f[k][j-1];
                }
                // cout << " --- " << f[i][j] << endl;
            }
        }
        return f[n][m];
    }
};