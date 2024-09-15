#include <vector>
using namespace std;

/*
96. 不同的二叉搜索树
https://leetcode-cn.com/problems/unique-binary-search-trees/

状态:
g[k]表示k个结点可以构造出的二叉搜索树的个数
f[i,k]表示以i为根节点、总共k个结点时，可构造出的二叉搜索树的个数
这样如果一共有k个结点，每个结点都可以轮番做一次根节点，这样出来的二叉搜索树肯定不一样
也就是说，g[k] = f[1,k] + f[2,k] + f[3,k] + ... + f[k,k] --(1)

边界:
g[0]=1 --空树
g[1]=1 --只有根节点

状态转移: [1,2,...,i-1][i][i+1,i+2,...,k]
则当 i 为根节点、总共k个结点时:
左子树有i-1个结点，这样可以构造出的二叉搜索树的个数为 g[i-1]
右子树有k-i个结点，这样可以构造出的二叉搜索树的个数为 g[k-i]
所以以i为根节点，总共k个结点时，可以构造出的二叉搜索树的个数为: f[i,k] = g[i-1]*g[k-i] --(2)

根据(1)(2)可以推导出:
g[k] = f[1,k] + f[2,k] + f[3,k] + ... + f[k,k]
= g[1-1]*g[k-1] + g[2-1]*g[k-2] + g[3-1]*g[k-3] + ... + g[k-1]*g[k-k]

目标: g[n]
*/

class Solution {
   public:
    int numTrees(int n) {
        vector<int> g(n + 1);
        g[0] = 1;
        g[1] = 1;
        // 一共k个结点。区间长度为k
        for (int k = 2; k <= n; ++k) {
            // 以i为根节点。区间左边长度为i-1，区间右边长度为k-i
            for (int i = 1; i <= k; ++i) {
                g[k] += g[i - 1] * g[k - i];
            }
        }
        return g[n];
    }
};