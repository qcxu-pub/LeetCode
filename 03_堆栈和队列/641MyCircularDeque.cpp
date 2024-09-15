#include <deque>
using namespace std;

/*
641. 设计循环双端队列
https://leetcode-cn.com/problems/design-circular-deque/

跟一般双端队列的区别：多了一个最大长度的限制
*/

class MyCircularDeque {
   public:
    MyCircularDeque(int k) {
        maxLen = k;
    }

    bool insertFront(int value) {
        if (q.size() < maxLen) {
            q.push_front(value);
            return true;
        } else {
            return false;
        }
    }

    bool insertLast(int value) {
        if (q.size() < maxLen) {
            q.push_back(value);
            return true;
        } else {
            return false;
        }
    }

    bool deleteFront() {
        if (!q.empty()) {
            q.pop_front();
            return true;
        } else {
            return false;
        }
    }

    bool deleteLast() {
        if (!q.empty()) {
            q.pop_back();
            return true;
        } else {
            return false;
        }
    }

    int getFront() {
        if (q.empty())
            return -1;
        else
            return q.front();
    }

    int getRear() {
        if (q.empty())
            return -1;
        else
            return q.back();
    }

    bool isEmpty() {
        return q.empty();
    }

    bool isFull() {
        if (q.size() == maxLen)
            return true;
        else
            return false;
    }

   private:
    deque<int> q;
    int maxLen;
};
