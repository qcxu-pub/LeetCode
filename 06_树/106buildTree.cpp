#include <vector>
using namespace std;

#include <iostream>

/*
106. 从中序与后序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

思路同105
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        int n = inorder.size();
        return build(0, n - 1, 0, n - 1);
    }

   private:
    vector<int> inorder;
    vector<int> postorder;

    // inorder[l1...r1], postorder[l2...r2]
    TreeNode* build(int l1, int r1, int l2, int r2) {
        if (l2 > r2)
            return nullptr;

        // left: inorder[l1,mid-1], postorder[l2,l2+(mid-l1)-1] --> 两边delta相等
        // root: inorder[mid], postorder[r2]
        // right:inorder[mid+1,r1], postorder[l2+(mid-l1)+1,r2-1]

        TreeNode* root = new TreeNode(postorder[r2]);
        int mid = l1;
        for (int i = l1; i <= r1; ++i) {
            if (inorder[i] == root->val) {
                mid = i;
                break;
            }
        }

        root->left = build(l1, mid - 1, l2, l2 + (mid - l1) - 1);
        root->right = build(mid + 1, r1, l2 + (mid - l1), r2 - 1);
        return root;
    }
};
