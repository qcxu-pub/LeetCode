#include <algorithm>
#include "limits.h"
using namespace std;

/*
124. 二叉树中的最大路径和
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

负数会拉低总和
返回的只能是单边之和，不然连不上
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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

   private:
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int lans = max(max(root->val, max(left, right) + root->val), left + right + root->val);
        ans = max(ans, lans);
        return max(root->val, max(left, right) + root->val);
    }
};