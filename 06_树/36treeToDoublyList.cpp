/*
剑指 Offer 36. 二叉搜索树与双向链表
https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

中序遍历 + 双向链表
*/

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

   private:
    Node* head;
    Node* pre;

    void dfs(Node* root) {
        // 递归边界
        if (root == nullptr)
            return;
        // 左
        dfs(root->left);
        // 建立双向链表
        if (head == nullptr) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        // 右
        dfs(root->right);
    }
};