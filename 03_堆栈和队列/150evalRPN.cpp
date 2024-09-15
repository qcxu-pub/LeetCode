#include <stack>
#include <string>
#include <vector>
using namespace std;

/*
150. 逆波兰表达式求值
https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

利用栈，求后缀表达式
*/


class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                int z = calc(x, y, token);
                stk.push(z);
            } else {
                stk.push(atoi(token.c_str()));
            }
        }
        return stk.top();
    }

   private:
    stack<int> stk;
    int calc(int x, int y, string token) {
        if (token == "+")
            return x + y;
        if (token == "-")
            return x - y;
        if (token == "*")
            return x * y;
        if (token == "/")
            return x / y;
        return 0;
    }
};