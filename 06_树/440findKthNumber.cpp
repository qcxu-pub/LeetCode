#include <algorithm>
using namespace std;

/*
440. 字典序的第K小数字
https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/

思路:
10叉树的先序遍历,找到按照先序遍历的第k个节点
每次在prefix(1,2,...)上有两种走法: 往右、往下。取决于当前prefix下有多少结点
>k就往下，<k就往右。往下*10，往右+1

假设n=109，那每一层下，每一个prefix节点下，每一层结点个数
1                                                                               cur=1, next=2                                    next-cur=1
10                                            11  12  13  14  15 16 17 18 19    cur*10=10, next*10=20                            next-cur=10
100 101 102 103 104 105 106 107 108 109                                         cur*100=100,min(next*100,n+1)=min(200,110)=119   next-cur=10
*/

class Solution {
   public:
    int findKthNumber(int n, int k) {
        int p = 1;       // 最终要找的那个是p=k
        int prefix = 1;  // 1 --> 往下10/往右2?
        while (p < k) {
            long long count = getCount(prefix, n);
            // 往下找
            if (p + count > k) {
                p += 1;
                prefix *= 10;
            }
            // 往右找
            else {
                p += count;
                prefix += 1;
            }
        }
        // p == k
        return prefix;
    }

   private:
    long long getCount(long long prefix, long long n) {
        long long curr = prefix;
        long long next = curr + 1;
        long long count = 0;
        // 在可行范围内
        while (curr <= n) {
            count += min((long long)next, (long long)n + 1) - curr;
            // 下一层，直到下一层的数字大小>n为止
            curr *= 10;
            next *= 10;
        }
        return count;
    }
};