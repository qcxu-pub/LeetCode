/*
69. x 的平方根
https://leetcode-cn.com/problems/sqrtx/

找最大的ans，使 ans*ans <= x
例如：x = 8
a = [1,2,3,4,5,...]
--> a*a<=8? [1,1,0,0,0,...]  --> 0/1分段
*/

class Solution {
   public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left < right) {
            // 因为后面是left=mid，所以不能向下取整，要+1，不然会死循环
            int mid = left + (right - left) / 2 + 1;
            if (mid <= x / mid) {  // mid * mid <= x 怕溢出了
                left = mid;        // 因为找的是最大值
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};


/*
上面那题是针对整数开方，下面是对实数开方。实数二分。
*/

class Solution2 {
   public:
    int mySqrt(int x) {
        return (int)(myRealSqrt(x));
    }

   private:
    double myRealSqrt(double x) {
        double left = 0, right = x;
        while (right - left > 1e-7) {
            double mid = (left + right) / 2; // 这里是精确值
            if (mid * mid <= x)
                left = mid;
            else
                right = mid;
        }
        return right;
    }
};