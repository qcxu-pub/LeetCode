/*
226. 翻转二叉树
https://leetcode-cn.com/problems/invert-binary-tree/

思路：用递归解决
1.递归边界：叶子结点
2.本层逻辑：左右翻转
3.子问题：左右子树内部也需要翻转
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
    TreeNode* invertTree(TreeNode* root) {
        // 递归边界
        if (root == nullptr)
            return nullptr;

        // 本层逻辑
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 子问题
        invertTree(root->left);
        invertTree(root->right);

        // 没有共享变量，不需要还原现场

        return root;
    }
};
