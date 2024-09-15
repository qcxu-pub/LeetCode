#include <vector>
#include <queue>
using namespace std;

/*
429. N 叉树的层序遍历
https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

从返回结果看，不仅循序，还要把同一层的放在同一个vector里面。所以要带上层数信息。
*/

struct Node {
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
   public:
    vector<vector<int> > levelOrder(Node* root) {
        if (root == nullptr)
            return ans;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<Node*, int> nodeLevel = q.front();
            q.pop();

            Node* node = nodeLevel.first;
            int level = nodeLevel.second;
            if (ans.size() <= level) {
                vector<int> ans_level;
                ans.push_back(ans_level);
            }
            ans[level].push_back(node->val);

            for (Node* child : node->children) {
                q.push(make_pair(child, level + 1));
            }
        }
        return ans;
    }

   private:
    queue<pair<Node*, int> > q;
    vector<vector<int> > ans;
};
