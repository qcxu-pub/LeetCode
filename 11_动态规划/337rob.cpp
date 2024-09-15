#include <unordered_map>
#include <vector>
using namespace std;

/*
337. 打家劫舍 III
https://leetcode-cn.com/problems/house-robber-iii/

状态:
f[x,0] 表示以x为根的子树，在不打劫x的情况下，能够盗取的最高金额
f[x,1] 表示以x为根的子树，在打劫x的情况下，能够盗取的最高金额
状态转移:
f[x,0] = sum_y(max{f[y,0],f[y,1]}), y is son of x  --max就是在找最优子结构的代表
f[x,1] = val(x) + sum_y(f[y,0]), y is son of x
目标:
max{f[root,0], f[root,1]}

把动规套在dfs里面
递归遍历树，回溯时从底往上递推
图的dfs需要开visied数组，树不需要
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int rob(TreeNode* root) {
        f[nullptr] = {0, 0};  // dfs边界
        dfs(root);
        return max(f[root][0], f[root][1]);
    }

   private:
    // 数组长度不知道，所以开的是unordered_map = {TreeNode: vector<int>(2)} = {x:{f[x,0],f[x,1]}}
    unordered_map<TreeNode*, vector<int> > f;

    // 这里返回vector也可，这样边界就不用初始化nullptr的key了
    void dfs(TreeNode* root) {
        // 边界
        if (root == nullptr)
            return;

        f[root] = {0, 0};

        // 递归子树
        dfs(root->left);
        dfs(root->right);

        // 本层逻辑
        f[root][0] = max(f[root->left][0], f[root->left][1]) + max(f[root->right][0], f[root->right][1]);
        f[root][1] = f[root->left][0] + f[root->right][0] + root->val;
    }
};