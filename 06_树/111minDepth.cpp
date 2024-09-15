#include <algorithm>
#include "limits.h"
using namespace std;

/*
111. 二叉树的最小深度
https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

用递归解决
思路1：自底向上统计信息。最大深度=min(左子树最大深度, 右子树最大深度) + 1
思路2：自顶向下维护信息。深度作为全局共享变量，level+1
变量+1，到叶子结点更新答案。注意要还原现场
*/

/*思路2*/
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
    int minDepth(TreeNode* root) {
        calc(root);
        return ans == INT_MAX ? 0 : ans;
    }

   private:
    int depth = 0;
    int ans = INT_MAX;

    void calc(TreeNode* root) {
        // 递归边界
        if (root != nullptr && root->left == nullptr && root->right == nullptr) {
            ans = min(ans, depth + 1);
            return;
        } else if (root == nullptr)
            return;

        // 本层逻辑，下一层left，还原现场
        depth += 1;
        calc(root->left);
        // depth -= 1

        // 本层逻辑，下一层right，还原现场
        // depth += 1;
        calc(root->right);
        depth -= 1;
    }
};


/*
思路1,同104
有一个坑: 当叶子结点深度为0的时候，说明没有叶子结点，那在根节点计算min的时候，就不能算进去了
case: [2,null,3,null,4,null,5,null,6]  --> 输出的应该是5，不是1
*/

class Solution {
   public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }

   private:
    int dfs(TreeNode* root) {
        // 边界条件
        if (root == nullptr)
            return 0;
        // 计算左子树/右子树的最大深度
        int leftResult = dfs(root->left);
        int rightResult = dfs(root->right);
        // root结点汇总
        int result = 0;
        if (leftResult == 0)
            result = rightResult;
        else if (rightResult == 0)
            result = leftResult;
        else
            result = min(leftResult, rightResult);
        return result + 1;
    }
};