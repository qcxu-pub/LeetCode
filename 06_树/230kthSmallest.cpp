/*
230. 二叉搜索树中第K小的元素
https://leetcode.cn/problems/kth-smallest-element-in-a-bst/

思路：二叉搜索树的中序遍历，就是递增的序列
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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

   private:
    int n = 0;
    int ans = -1;
    void dfs(TreeNode* root, int k) {
        // 边界条件
        if (root == nullptr)
            return;
        // 左
        dfs(root->left, k);
        // 中
        n += 1;
        if (n == k && ans == -1) {
            ans = root->val;
            return;
        }
        // 右
        dfs(root->right, k);
    }
};