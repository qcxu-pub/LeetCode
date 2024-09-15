#include <unordered_map>
#include <vector>
using namespace std;

#include <cstdio>
#include <iostream>

/*
124. 二叉树中的最大路径和
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

树那一章也做过这个题目。这里多一个打印路径

状态:
    f[x]: 以x为根节点的最大路径和
状态转移:
    1.只取根节点: f[x] = x->val, if f[x->left]<0 && f[x->right]<0
    2.根节点+左孩子: f[x] = x->val + f[x->left], if f[x->left]>0 && f[x->left]>f[x->right]
    3.根节点+右孩子: f[x] = x->val + f[x->right], if f[x->right]>0 && f[x->right]>f[x->left]
    f[x] = max{上面3种情况的f[x]}

    根节点+左孩子+右孩子: x->val + f[x->left] + f[x->right] --只可用于更新答案，但不能进入状态转移
    所以，ans[x] = max{f[x], x->val + f[x->left] + f[x->right]}
目标:
    max{ans[x]}
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
        // 初始化
        head = root;
        // 从root开始递归
        dfs(root);
        // 打印路径
        print(head);
        // 目标
        return ans;
    }

   private:
    int ans = -1e9;
    unordered_map<TreeNode*, vector<TreeNode*> > path;  // {root: {leaf_left, leaf_right}}
    unordered_map<TreeNode*, int> f; // {root: maxPathSum}
    TreeNode* head;

    void dfs(TreeNode* root) {
        // 边界
        if (root == nullptr) {
            f[root] = 0;
            return;
        }
        //  递归
        dfs(root->left);
        dfs(root->right);
        int left = f[root->left];
        int right = f[root->right];
        // 本层状态转移
        int curr = root->val;
        if (left <= 0 && right <= 0) {
            f[root] = curr;
            path[root] = {nullptr, nullptr};
        } else if (left > 0 && left >= right) {
            f[root] = curr + left;
            path[root] = {root->left, nullptr};
        } else if (right > 0 && right >= left) {
            f[root] = curr + right;
            path[root] = {nullptr, root->right};
        }
        //
        if (curr + left + right > f[root]) {
            path[root] = {root->left, root->right};
        }
        // 更新答案
        if (ans < max(f[root], curr + left + right)) {
            ans = max(f[root], curr + left + right);
            head = root;
        }
        return;
    }

    vector<int> route;
    void getRoute(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* left = path[root][0];
        TreeNode* right = path[root][1];

        if (f[left] >= f[right])  // f[nullptr] = -1e9 不可能成为大的那个了
            getRoute(root->left);
        else
            getRoute(root->right);

        // 回溯的时候push路径
        route.push_back(root->val);
        return;
    }

    void print(TreeNode* head) {
        f[nullptr] = -1e9;

        // 左子树，从叶子结点开始打印
        getRoute(head->left);
        vector<int> routeLeft = this->route;

        // 右子树，从根节点开始打印
        this->route = {};
        getRoute(head->right);
        vector<int> routeRight = this->route;

        // merge 左右子树的路径
        vector<int> routeMerge = routeLeft;
        routeMerge.push_back(head->val);
        for (int i = routeRight.size() - 1; i >= 0; --i)
            routeMerge.push_back(routeRight[i]);

        // 打印
        for (int v : routeMerge)
            cout << v << ",";
    }
};