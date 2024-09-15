/*
114. 二叉树展开为链表
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

左子树的最右下结点，是右子树的父节点。这样可以不断地把左子树的右边拉入链表。实现前序遍历
prev->right = curr->right
curr->right = curr->left
+二分法
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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        flatten(root->left);
        flatten(root->right);

        if (root->left != nullptr) {
            TreeNode* prev = root->left;
            while (prev->right != nullptr)
                prev = prev->right;
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
        return;
    }
};