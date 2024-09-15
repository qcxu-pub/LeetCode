#include <queue>
using namespace std;

/*
225. 用队列实现栈
https://leetcode-cn.com/problems/implement-stack-using-queues/

一个队列实现，每次要取栈顶/队尾（最后入的元素的时候），就把队列前面的依次加入尾部，只留最后一个返回。
*/

class MyStack {
   public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push_back(q.front());
            q.pop_front();
        }
        int ans = q.front();
        q.pop_front();
        return ans;
    }

    /** Get the top element. */
    int top() {
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push_back(q.front());
            q.pop_front();
        }
        int ans = q.front();
        q.push_back(q.front());
        q.pop_front();
        return ans;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

   private:
    deque<int> q;
};