#include <string>
#include <vector>
using namespace std;

/*
22. 括号生成
https://leetcode.cn/problems/generate-parentheses/

在 05_递归和分治 里做过这道题。当时是用分治做的

蛮力搜索: 指数型，每个位置放两种括号之一，最后验证。O(n*2^(2n))
剪枝: 组合型，2n个位置选n个放左括号，剩余放右括号，最后验证。O(n*C(2n,n))
再次剪枝: 实时维护左右括号数量，不合法及时停止

*/


/*暴力搜索*/

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs(0);
        return ans;
    }

   private:
    int n;
    string s;
    vector<string> ans;

    void dfs(int i) {
        // 边界条件
        if (i == 2 * n) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        //
        s.push_back('(');
        dfs(i + 1);
        s.pop_back();  // 还原现场
        //
        s.push_back(')');
        dfs(i + 1);
        s.pop_back();  // 还原现场
    }

    // 可以利用栈看时候合理。但这里就一种括号，所以用变量就好了
    bool isValid(string s) {
        int left = 0;
        for (char& ch : s) {
            if (ch == '(')
                ++left;
            else {
                if (left <= 0)
                    return false;
                else
                    --left;
            }
        }
        return left == 0;
    }
};

/*
加入剪枝: '(', ')'分别计数，不要混起来一起计数了。如果'('数量>n，或者')'数量>n，不合理，直接退出
所以加入状态 left 和 right ，分别统计left和right的数量
组合型
*/
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs(0, 0, 0);
        return ans;
    }

   private:
    int n;
    string s;
    vector<string> ans;

    void dfs(int i, int left, int right) {
        // 递归边界，不合法
        if (left > n || right > n)
            return;
        // 递归边界，正常边界
        if (i == 2 * n) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        //
        s.push_back('(');
        dfs(i + 1, left + 1, right);
        s.pop_back();
        //
        s.push_back(')');
        dfs(i + 1, left, right + 1);
        s.pop_back();
    }

    bool isValid(string s) {
        int left = 0;
        for (char& ch : s) {
            if (ch == '(')
                ++left;
            else {
                if (left <= 0)
                    return false;
                else
                    --left;
            }
        }
        return left == 0;
    }
};

/*
继续剪枝: 随时判断isValid，不合法即使退出
这样isValid返回结果只要是left>0
*/

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs(0, 0, 0);
        return ans;
    }

   private:
    int n;
    string s;
    vector<string> ans;

    void dfs(int i, int left, int right) {
        // 递归边界，不合法
        if (left > n || right > n || !isValid(s)) //
            return;
        // 递归边界，正常边界
        if (i >= 2 * n) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        //
        s.push_back('(');
        dfs(i + 1, left + 1, right);
        s.pop_back();
        //
        s.push_back(')');
        dfs(i + 1, left, right + 1);
        s.pop_back();
    }

    bool isValid(string s) {
        int left = 0;
        for (char& ch : s) {
            if (ch == '(')
                ++left;
            else {
                if (left <= 0)
                    return false;
                else
                    --left;
            }
        }
        return true;  // ((( --ok
    }
};

/*
极简代码
递归时就考虑 right > left
*/

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return ans;
    }

   private:
    vector<string> ans;

    void dfs(string s, int left, int right) {
        if (left == 0 && right == 0)
            ans.push_back(s);
        if (left > 0)
            dfs(s + "(", left - 1, right);
        if (right > 0 && right > left)
            dfs(s + ")", left, right - 1);
    }
};
