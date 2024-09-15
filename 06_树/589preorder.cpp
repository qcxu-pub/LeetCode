#include <vector>
#include <stack>
using namespace std;

/*
589. N 叉树的前序遍历
https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/

*/

class Node {
   public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

/*递归*/
class Solution {
   public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }

   private:
    vector<int> ans;
    void dfs(Node* root) {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        for (Node* child : root->children)
            dfs(child);
    }
};

/*迭代法。自己写个栈实现。拿栈顶出来扩展*/
class Solution2 {
   public:
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return ans;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            ans.push_back(node->val);
            stk.pop();
            for (int i = node->children.size() - 1; i >= 0; --i) {
                stk.push(node->children[i]);
            }
        }
        return ans;
    }

   private:
    vector<int> ans;
    stack<Node*> stk;
};
