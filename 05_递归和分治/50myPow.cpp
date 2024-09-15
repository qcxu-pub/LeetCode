#include <unordered_map>
#include "limits.h"
using namespace std;

/*
50. Pow(x, n)
https://leetcode-cn.com/problems/powx-n/

 */

class Solution {
   public:
    double myPow(double x, int n) {
        // int 范围：[-2^31, 2^31-1]
        if (n == -(1ll << 31))
            return 1.0 / (myPow(x, -(n + 1)) * x);
        if (n < 0)
            return 1.0 / myPow(x, -n);
        if (n == 0)
            return 1;

        double temp = myPow(x, n / 2);  // 向下取整
        if (n % 2 == 1)
            return temp * temp * x;
        else
            return temp * temp;
    }
};

/*
int范围晕的可以看这个
*/

class Solution {
   public:
    double myPow(double x, int n) {
        h[0] = 1.0;
        h[1] = 1.0 * x;
        return pow(x, n);
    }

   private:
    unordered_map<int, double> h;  // {n: x^n}
    double pow(double x, int n) {
        if (n == INT_MIN)
            return 1.0 / pow(x, INT_MAX) * 1.0 / x;
        if (n < 0)
            return 1.0 / pow(x, -n);
        if (h.find(n) != h.end())
            return h[n];

        double ans;
        if (n % 2 == 0) {
            ans = pow(x, n / 2) * pow(x, n / 2);
            h[n] = ans;
        } else if (n % 2 == 1) {
            ans = 1.0 * x * pow(x, n / 2) * pow(x, n / 2);
            h[n] = ans;
        }
        return ans;
    }
};