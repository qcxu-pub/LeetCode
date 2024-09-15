
/*
701. 二叉搜索树中的插入操作
https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/

二叉搜索树的插入
1.先查找到要插入的位置，若存在则放弃插入（或把val对应的结点计数+1）
2.若不存在则直接插入
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 替代掉原来为空的结点
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};