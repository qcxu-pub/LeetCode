#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
22. 括号生成
https://leetcode-cn.com/problems/generate-parentheses/

思路1：递归/前面说的排列组合问题。（在 08_深搜和广搜 里，有暴力递归和对应的剪枝优化解法）

思路2：用分治解决。这里用这种方式。怎么分？
例如：n=3
_ _|_ _ _ _  ()(())  ()()()
_ _ _ _|_ _  (())()  ()()()  -->
跟上面重复了。所以不重不漏要注意一个点：找第一个不可划分的整体。

所以这样分：
s = ( A )  B
n    k-1  n-k  --> 枚举第一个划分点k，保证第一段是不可分的整体。

k=1 (A) A=0对括号；B=n-k=2对括号，这是个子问题。()()(),()(())
k=2 (A) A=1对括号；B=n-k=1对括号。(())()
k=3 (A) A=2对括号；B=n-k=0对括号。(()()),((()))

划分子问题，是加法原理，解决方案总和就是总方案。
解决同一个子问题的每一种方案的组合，是乘法原理。
*/

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        // 递归边界
        if (n == 0)
            return {""};

        vector<string> ans;
        // 加法原理
        for (int k = 1; k <= n; ++k) {
            vector<string> A = generateParenthesis(k - 1);
            vector<string> B = generateParenthesis(n - k);
            // 乘法原理
            for (string& a : A) {
                for (string& b : B) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        return ans;
    }
};

/*
上一段代码的问题：中间结果没有保存，导致重复计算，比如 n=2被调用多次。
下面的优化点：记忆化。
*/

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        // 递归边界
        if (n == 0)
            return {""};
        // 记忆化
        if (store.find(n) != store.end())
            return store[n];

        vector<string> ans;
        // 加法原理
        for (int k = 1; k <= n; ++k) {
            vector<string> A = generateParenthesis(k - 1);
            vector<string> B = generateParenthesis(n - k);

            // 乘法原理
            for (string& a : A) {
                for (string& b : B) {
                    string s = "(" + a + ")" + b;
                    ans.push_back(s);
                }
            }
        }
        store[n] = ans;
        return ans;
    }

   private:
    unordered_map<int, vector<string> > store;
};
