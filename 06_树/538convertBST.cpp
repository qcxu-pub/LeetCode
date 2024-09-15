/*
538. 把二叉搜索树转换为累加树
https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

二叉搜索树右子树的所有结点>=当前结点，所以就是要把右子树的所有结点累积和加到左子树上
反中序遍历
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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        convertBST(root->right);  // 更新root->right->val
        sum += root->val;
        root->val = sum;  // 更新root->val
        convertBST(root->left);
        return root;
    }
    
   private:
    int sum = 0;
};