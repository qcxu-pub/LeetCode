#include <algorithm>
using namespace std;

/*
104. 二叉树的最大深度
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

用递归解决
思路1：自底向上统计信息。最大深度=max(左子树最大深度, 右子树最大深度) + 1
思路2：自顶向下维护信息。深度作为全局共享变量，level+1
变量+1，到叶子结点更新答案。注意要还原现场

这道题用思路1，111用思路2
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
    int maxDepth(TreeNode* root) {
        // 递归边界
        if (root == nullptr)
            return 0;

        // 本层逻辑 & 子问题
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};