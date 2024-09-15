#include <vector>
using namespace std;

/*
776. 拆分二叉搜索树 (median)
https://leetcode.cn/problems/split-bst/

给你一棵二叉搜索树（BST）、它的根结点 root 以及目标值 V。
请将该树按要求拆分为两个子树：其中一个子树结点的值都必须小于等于给定的目标值 V；另一个子树结点的值都必须大于目标值 V；树中并非一定要存在值为 V 的结点。

除此之外，树中大部分结构都需要保留，也就是说原始树中父节点 P 的任意子节点 C，假如拆分后它们仍在同一个子树中，那么结点 P 应仍为 C 的子结点。

你需要返回拆分后两个子树的根结点 TreeNode，顺序随意。

示例：
输入：root = [4,2,6,1,3,5,7], V = 2
输出：[[2,1],[4,3,6,null,null,5,7]]

*/

/*
思路:
递归解决这道题
1. if root->val < v --> 切分右子树 ans[0],ans[1]
    root->val < ans[0] < root->right->val --> root->right = ans[0]
    ans[1] > root->right->val  --> 独立一颗右子树
2. if root->val > v --> 切分左子树 ans[0],ans[1]
    root->val > ans[1] > root->left->val  --> root->left = ans[1]
    ans[0] < root->left->val  --> 独立一颗左子树
*/

struct TreeNode {
    int val;
    TreeNode* left; 
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
    vector<TreeNode*> splitBST(TreeNode* root, int v) {
        if (root == nullptr)
            return {nullptr, nullptr};
            
        if (root->val < v) {
            vector<TreeNode*> ans = splitBST(root->right, v);
            root->right = ans[0];
            return {root, ans[1]};
        } else if (root->val > v) {
            vector<TreeNode*> ans = splitBST(root->left, v);
            root->left = ans[1];
            return {ans[0], root};
        }
    }
};