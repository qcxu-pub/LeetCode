#include <string>
#include <vector>
using namespace std;

/*
10. 正则表达式匹配
https://leetcode-cn.com/problems/regular-expression-matching/

caaab ca*b  --true
caaab ca*ab --true
那*配多少字母? 分支

跟LCS问题很像。都是基于前面i,j子问题的动规
(i,j)前面已经配好了，考虑之后的情况。前面已经配好的是个子问题。-->状态f[i,j]

  i      j
12345  123
caaaa  ca*
假设p[j]=*，那就不停地把s[i]字符包进*里。直到s[i]!=p[j-1]&&p[j-1]!='.'。所以停止之后的子问题是f[i,j-2]
f[5,3] <- f[4,3] <- f[3,3] <- f[2,3] <- f[1,3] <- f[1,1]

状态: f[i,j]表示s的前i个字符，p的前j个字符，能否匹配。具体是怎么匹配的不关心
状态转移:
1.如果p[j]==a~z
  f[i,j] = f[i-1,j-1] if s[i] == p[j]
         = false      if s[i] != p[j]
2.如果p[j]=='.'
  f[i,j] = f[i-1,j-1]
3.如果p[j]=='*'
  继续配: f[i,j] = f[i-1,j] if s[i]==p[j-1] || p[j-1]=='.'  相当于把s[i]包到*里面
  不配了: f[i,j] = f[i,j-2]  相当于 *=0

目标: f[n,m]
初值: f[0,0]=true, f[0][j]=true  *可以是0,所以 x* / .* 全部一定是true
*/

class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        s = " " + s;
        p = " " + p;

        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;  // 空对空
        // 前缀如果都是 x* / .* ，这里的 * 可以=0，也就匹配了空字符串
        for (int j = 2; j <= m; j += 2) {
            if (p[j] == '*')
                f[0][j] = true;
            else
                break;
        }

        // 递推
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // cout << "i=" << i << ",j=" << j << ",s[i]=" << s[i] << ,p[j]=" << p[j] << " --- "; p=字母
                
                if (p[j] >= 'a' && p[j] <= 'z' && s[i] == p[j]) {
                    // cout << "case 1";
                    f[i][j] = f[i - 1][j - 1];
                }

                else if (p[j] >= 'a' && p[j] <= 'z' && s[i] != p[j]) {
                    // cout << "case 2";
                    f[i][j] = false;
                }

                // p=.
                else if (p[j] == '.') {
                    // cout << "case 3";
                    f[i][j] = f[i - 1][j - 1];
                }

                // p=*
                else {
                    // cout << "case 4";
                    // 不能再包了写前面，先往更前面的找。比如，s="a", p="ab*a*"，如果先走继续包的逻辑，出来的是false
                    f[i][j] = f[i][j] || f[i][j - 2];
                    // 继续包
                    if (s[i] == p[j - 1] || p[j - 1] == '.')
                        f[i][j] = f[i][j] || f[i - 1][j];
                }

                // cout << " --- f[i][j] = " << f[i][j] << endl;
            }
        }
        return f[n][m];
    }
};
