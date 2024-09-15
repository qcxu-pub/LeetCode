/*
235. 二叉搜索树的最近公共祖先
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

可利用二叉搜索树的值的大小特性做
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        ans = nullptr;
        dfs(root);
        return ans;
    }

   private:
    TreeNode* p;
    TreeNode* q;
    TreeNode* ans;

    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->val < p->val && root->val < q->val)
            dfs(root->right);
        else if (root->val > p->val && root->val > q->val)
            dfs(root->left);
        else {
            ans = root;
            return;
        }
    }
};