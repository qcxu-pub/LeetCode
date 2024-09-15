#include "limits.h"

/*
98. 验证二叉搜索树
https://leetcode-cn.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
        // INT_MIN = -(1<<31), INT_MAX=(1<<31)-1
    }

   private:
    bool check(TreeNode* root, long long rangeLeft, long long rangeRight) {
        // 递归边界
        if (root == nullptr)
            return true;

        // 本层逻辑
        // cout << root->val << "," << rangeLeft << "," << rangeRight;
        if ((long long)root->val < rangeLeft || (long long)root->val > rangeRight)
            return false;

        // 子问题
        // 左子树要严格小于，右子树要严格大于
        // +1/-1 INT 可能越界，所以计算用 long long
        return check(root->left, rangeLeft, (long long)root->val - 1) &&
               check(root->right, (long long)root->val + 1, rangeRight);
    }
};