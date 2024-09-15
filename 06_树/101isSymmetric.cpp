/*
101. 对称二叉树
https://leetcode-cn.com/problems/symmetric-tree/

深度优先遍历。左子树的左节点=右子树的右结点 / 左子树的右结点=右子树的左节点
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;
        return dfs(root->left, root->right);
    }

   private:
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};