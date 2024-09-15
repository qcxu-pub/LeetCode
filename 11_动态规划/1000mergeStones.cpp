#include <vector>
using namespace std;

/*
1000. 合并石头的最低成本
https://leetcode-cn.com/problems/minimum-cost-to-merge-stones/

一旦相邻的合并了，数组就变了
所以把顺序倒过来。先把左右两边合完，然后考虑本层的合并。思路同312

那这里的最优子问题是什么？
状态: f[l,r]表示l~r合成一堆的最低成本？不是的！它可以合成若干堆，然后跟上一层的其他凑成k堆做合并，再合成一堆
例如，假设 k = 3，那下面的[l,r]应该是合成2堆才对
l x x | x x r | x x x
那如何表示l~r合成若干堆？信息不够，就加状态，+目标堆数

状态: f[l,r,i]表示把l~r合并成i堆的最低成本
决策1: 恰好凑成k堆，合成1堆
       f[l,r,1] = f[l,r,k] + sum(nums[p]), 其中,l<=p<=r
决策2: 分成两个子问题，l~p 合成 j 堆，p+1~r 合成 i-j 堆
        f[l,r,i] = min{f[l,p,j] + f[p+1,r,i-j]}, 其中,l<=p<r, 1<=j<i
时间复杂度: l=O(n), r=O(n), i=O(k), p=O(n), j=O(k) --> O(n^3 * k^2)

决策2可以优化：不需要枚举j，考虑第一堆是哪一段就可以了（这个思路跟递归分治第22题很像）
比如 k=3，那 1+2 和 2+1 是一样的 
f[l,r,i] = min{f[l,p,1] + f[p+1,r,i-1]}, 其中,l<=p<r
时间复杂度: O(n^3 * k)

*/

class Solution {
   public:
    int mergeStones(vector<int>& stones, int k) {
        // 这里不会访问到i-1,i+1这种位置，所以还是就 0~n-1 吧
        int n = stones.size();
        // 因为求最小值，所以全部初值正无穷。k的下标从1开始
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(k + 1, 1e9)));

        // 合法起点，原始的一堆合成一堆，不用合
        for (int l = 0; l < n; ++l)
            f[l][l][1] = 0;

        // 阶段: 区间长度。先算小区间，再算大区间。区间为1的就是合法起点
        for (int len = 2; len <= n; ++len) {
            // 状态: 左端点。len = r - l + 1, r < n
            for (int l = 0; l < n - len + 1; ++l) {
                int r = l + len - 1;

                // 决策2: 先算f[l][r][k], [l,r] 合成 k 堆 = 1堆 + (k-1)堆，[l,r]的切分点不定为p
                for (int i = 2; i <= k; ++i) {
                    // [l,r] 合成 i 堆 = [l,p] 合成 1 堆 + [p+1,r] 合成 i-1 堆
                    for (int p = l; p < r; ++p) {
                        // cout << "l=" << l <<",r=" << r << ",i=" <<i<<",p=" << p << endl;
                        f[l][r][i] = min(f[l][r][i], f[l][p][1] + f[p + 1][r][i - 1]);
                    }
                }

                // 决策1: k堆合1堆。sum可以用前缀和计算子段和的方式进行
                int sum = 0;
                for (int p = l; p <= r; ++p)
                    sum += stones[p];
                f[l][r][1] = min(f[l][r][1], f[l][r][k] + sum);
            }
        }
        return f[0][n - 1][1] == 1e9 ? -1 : f[0][n - 1][1];
    }
};