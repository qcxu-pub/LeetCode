#include <string>
#include <stack>
using namespace std;

/*
844. 比较含退格的字符串
https://leetcode-cn.com/problems/backspace-string-compare/

*/

class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        for (char& ch : s) {
            if (ch != '#')
                stk1.push(ch);
            else if (ch == '#' && !stk1.empty())
                stk1.pop();
        }
        for (char& ch : t) {
            if (ch != '#')
                stk2.push(ch);
            else if (ch == '#' && !stk2.empty())
                stk2.pop();
        }

        while (!stk1.empty() || !stk2.empty()) {
            if (stk1.size() != stk2.size())
                return false;
            if (stk1.top() != stk2.top())
                return false;
            stk1.pop();
            stk2.pop();
        }
        return true;
    }

   private:
    stack<char> stk1;
    stack<char> stk2;
};