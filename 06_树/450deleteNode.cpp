/*
450. 删除二叉搜索树中的节点
https://leetcode-cn.com/problems/delete-node-in-a-bst/

二叉搜索树的删除：基于查找+求后继实现
删除就说明，该点在二叉搜索树里是存在的。所以后继是通过相同结点的右子树一路往左找到的。所以后继点最多只有一颗右子树
1.把后继删了直接替代待删除的地方
2.把子树跟父亲相连
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            if (root->left == nullptr)
                return root = root->right;
            if (root->right == nullptr)
                return root = root->left;
            // 找后继结点
            TreeNode* next = root->right;
            while (next->left != nullptr)
                next = next->left;
            // 删除后继结点。后继结点位置由右子树替换。最后会落到 root->val == key && root->left == nullptr 这里
            root->right = deleteNode(root->right, next->val);
            // 题目要删除的结点，由后继结点替换
            root->val = next->val;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};