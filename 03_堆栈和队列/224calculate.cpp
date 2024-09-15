#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/*
227. 基本计算器 II: 支持 + - * /
https://leetcode-cn.com/problems/basic-calculator-ii/

在150题目上改进，利用栈，中缀转后缀
*/

class Solution {
   public:
    int calculate(string s) {
        s += ' ';
        string number = "";
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                number += ch;
                continue;
            } else {
                if (!number.empty()) {
                    tokens.push_back(number);
                    number = "";
                }
            }

            if (ch == ' ')
                continue;

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                int currRank = getRank(ch);
                while (!ops.empty() && getRank(ops.top()) >= currRank) {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(ch);
                continue;
            }
        }

        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }

        // for (string& token: tokens) {
        //     cout << token << ",";
        // }
        // cout << endl << "result =";

        return evalRPN(tokens);
    }

   private:
    stack<char> ops;
    vector<string> tokens;

    int getRank(char ch) {
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return 0;
    }

    // 150evalRPN
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

/*
224. 基本计算器: 支持 ( )
https://leetcode-cn.com/problems/basic-calculator/

在227题目上改进
*/

class Solution2 {
   public:
    int calculate(string s) {
        s += ' ';
        string number = "";
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                number += ch;
                continue;
            } else {
                if (!number.empty()) {
                    tokens.push_back(number);
                    number = "";
                }
            }

            if (ch == ' ')
                continue;

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                int currRank = getRank(ch);
                while (!ops.empty() && getRank(ops.top()) >= currRank) {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(ch);
                continue;
            }

            if (ch == '(') {
                ops.push(ch);
                continue;
            }

            if (ch == ')') {
                while (ops.top() != '(') {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
                continue;
            }
        }

        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }

        // for (string& token: tokens) {
        //     cout << token << ",";
        // }
        // cout << endl << "result =";

        return evalRPN(tokens);
    }

   private:
    stack<char> ops;
    vector<string> tokens;

    int getRank(char ch) {
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return 0;
    }

    // 150evalRPN
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


// 上述代码会报错，原因在于没有考虑负号

class Solution3 {
   public:
    int calculate(string s) {
        s += ' ';
        bool needZero = true;  //
        string number = "";
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                number += ch;
                needZero = false;
                continue;
            } else {
                if (!number.empty()) {
                    tokens.push_back(number);
                    number = "";
                }
            }

            if (ch == ' ')
                continue;

            if ((ch == '+' || ch == '-') && needZero) //
                tokens.push_back("0");

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                int currRank = getRank(ch);
                while (!ops.empty() && getRank(ops.top()) >= currRank) {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(ch);
                continue;
            }

            if (ch == '(') {
                ops.push(ch);
                needZero = true;  //
                continue;
            }

            if (ch == ')') {
                while (ops.top() != '(') {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
                needZero = false;  //
                continue;
            }
        }

        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }

        // for (string& token: tokens) {
        //     cout << token << ",";
        // }
        // cout << endl << "result =";

        return evalRPN(tokens);
    }

   private:
    stack<char> ops;
    vector<string> tokens;

    int getRank(char ch) {
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return 0;
    }

    // 150evalRPN
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
