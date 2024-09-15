#include <vector>
using namespace std;

/*
94. 二叉树的中序遍历
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }

   private:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
};