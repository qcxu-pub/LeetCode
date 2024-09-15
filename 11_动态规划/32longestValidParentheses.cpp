#include <string>
#include <vector>
using namespace std;

/*
32. 最长有效括号
https://leetcode-cn.com/problems/longest-valid-parentheses/

状态: f[i]表示到达第i个位置的最长连续有效括号个数 （本段的最长）
状态转移:
  i  1 2 3 4 5 6 7 8 9 10
     ) ( ( ) ( ( ) ) ) )
f[i] 0 0 0 2 0 0 2 6 8 0

f[8]的计算
idx = 7 - f[7] = 5, s[5] = '(' --> ok --> f[8] = f[idx-1] + f[8-1] + 2 = 2 + 2 + 2 = 6
f[9]的计算
idx = 8 - f[8] = 2, s[2] = '(' --> ok --> f[9] = f[idx-1] + f[9-1] + 2 = 0 + 6 + 2 = 8
f[10]的计算
idx = 9 - f[9] = 1, s[1] = ')' --> 跟前面不能形成有效括号，上一段连续结束。如果后面能形成连续括号，也要重新计数了，后面会利用到 f[idx-1]=0，idx-1就是当前位置

所以
1.如果s[i]='('，则 f[i]=0
2.如果s[i]=')' && s[i-1]='('，则 直接形成有效括号，f[i]=f[i-2]+2 --f[i-2]是上一段以')'结尾的连续有效括号长度
3.如果s[i]=')' && s[i-1]=')'，则 先找前面最近一个还没有匹配括号的位置 idx=(i-1)-f[i-1]
  如果f[idx]='('，那 +本段连续括号 +当前的')'，可以增长本段连续有效括号的长度，
  所以f[i]=f[idx-1]+f[i-1]+2 --f[idx-1]是上一段以')'结尾的的连续有效括号长度，f[i-1]+2是本段的连续有效括号长度

目标:
max{f[i]} --全局的最长

*/

class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size();
        s = " " + s;
        vector<int> f(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            if (s[i] == '(')
                continue;

            // s[i] = ')'
            if (s[i - 1] == '(') {
                if (i - 2 >= 0)  // 下标合法
                    f[i] = f[i - 2] + 2;
                else
                    f[i] = 2;
                continue;
            }

            if (s[i - 1] == ' ') {
                continue;
            }

            // s[i] = ')' && s[i-1] = ')'，找最近一个还没有匹配的括号，看类型
            int idx = (i - 1) - f[i - 1];
            if (idx >= 1 && s[idx] == '(') {
                if (idx - 1 >= 0)  // 下标合法
                    f[i] = f[idx - 1] + f[i - 1] + 2;
                else
                    f[i] = f[i - 1] + 2;
            }
        }

        // 全局max
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = max(ans, f[i]);

        return ans;
    }
};