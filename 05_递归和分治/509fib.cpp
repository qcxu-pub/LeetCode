/*
509. 斐波那契数
https://leetcode-cn.com/problems/fibonacci-number/

*/

class Solution {
   public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        this->n = n;
        arr[0] = 0;
        arr[1] = 1;
        recur(2); // 2->3->4->...->n
        return arr[n];
    }

   private:
    int arr[31];
    int n;

    void recur(int level) {
        if (level == n + 1)
            return;
        arr[level] = arr[level - 1] + arr[level - 2];
        recur(level + 1);
    }
};