#include <iostream>
using namespace std;

/*
236. 二叉树的最近公共祖先
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

思路：标记法。找一个最下的根结点，既有p也有q，这个根就是LCA
要找最下面的点，所以dfs回溯的时候，第一次有结果就是他了
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
        dfs(root);
        return ans;
    }

   private:
    TreeNode* p;
    TreeNode* q;
    TreeNode* ans;

    // <是否有p, 是否有q>
    pair<bool, bool> dfs(TreeNode* root) {
        if (root == nullptr)
            return {false, false};

        pair<bool, bool> leftResult = dfs(root->left);
        pair<bool, bool> rightResult = dfs(root->right);
        pair<bool, bool> result;
        result.first = root->val == p->val || leftResult.first || rightResult.first;
        result.second = root->val == q->val || leftResult.second || rightResult.second;

        if (result.first && result.second && ans == nullptr)
            ans = root;
        return result;
    }
};