#include <stack>
#include <string>
using namespace std;

/*
20. 有效的括号
https://leetcode-cn.com/problems/valid-parentheses/
*/


class Solution {
   public:
    bool isValid(string s) {
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                stk.push(ch);
            else {
                if (stk.empty())
                    return false;
                if (ch == ')' && stk.top() != '(')
                    return false;
                else if (ch == ']' && stk.top() != '[')
                    return false;
                else if (ch == '}' && stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

   private:
    stack<char> stk;
};