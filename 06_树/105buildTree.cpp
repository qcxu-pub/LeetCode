#include <vector>
using namespace std;

/*
105. 从前序与中序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

前序: 可以直接知道根是root[0]。但区分不了左子树和右子树
中序：利用前序知道了根在哪里，以根为界，就能知道左子树和右子树了
子树的具体还原，就是个子问题了。用递归解决
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        int n = preorder.size();
        return build(0, n - 1, 0, n - 1);
    }

   private:
    vector<int> preorder;
    vector<int> inorder;

    // preorder[l1...r1], inorder[l2...r2]
    TreeNode* build(int l1, int r1, int l2, int r2) {
        // 递归边界
        if (l1 > r1)
            return nullptr;

        // left: inorder[l2,mid-1], preorder[l1+1,l1+(mid-1-l2+1)]=preorder[l1+1,l1+(mid-l2)]
        // root: inorder[mid], preorder[l1]
        // right: inorder[mid+1,r2], preorder[l1+(mid-l2)+1,r1]
        TreeNode* root = new TreeNode(preorder[l1]);
        int mid = l2;
        while (inorder[mid] != root->val)
            ++mid;
        root->left = build(l1 + 1, l1 + (mid - l2), l2, mid - 1);
        root->right = build(l1 + (mid - l2) + 1, r1, mid + 1, r2);
        return root;
    }
};