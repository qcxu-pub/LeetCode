#include <stack>
using namespace std;

/*
232. 用栈实现队列
https://leetcode-cn.com/problems/implement-queue-using-stacks/

思路：用两个栈，输入栈和输出栈
*/

class MyQueue {
   public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!output.empty()) {
            int ans = output.top();
            output.pop();
            return ans;
        }
        // output.empty()
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    /** Get the front element. */
    int peek() {
        if (!output.empty()) {
            return output.top();
        }
        // output.empty()
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (input.empty() && output.empty())
            return true;
        else
            return false;
    }

   private:
    stack<int> input;
    stack<int> output;
};