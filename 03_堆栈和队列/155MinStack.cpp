#include <stack>
using namespace std;

/*
155. 最小栈
https://leetcode-cn.com/problems/min-stack/
*/


class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        stk.push(x);
        if (preMin.empty())
            preMin.push(x);
        else
            preMin.push(min(preMin.top(), x));
    }

    void pop() {
        stk.pop();
        preMin.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return preMin.top();
    }

   private:
    stack<int> stk;
    stack<int> preMin;
};