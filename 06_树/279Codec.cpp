#include <string>
#include <vector>
using namespace std;

/*
297. 二叉树的序列化与反序列化
https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(ans, root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        this->data = data;
        return restore();
    }

   private:
    void dfs(string& ans, TreeNode* root) {
        if (root == nullptr) {
            ans += "n,";
            return;
        }
        ans += to_string(root->val) + ",";
        dfs(ans, root->left);
        dfs(ans, root->right);
    }

    int idx = 0;
    string data;
    
    TreeNode* restore() {
        if (data[idx] == 'n') {
            idx += 2;  //'n,'
            return nullptr;
        }
        if (data.size() == 0 || idx == data.size() - 1)
            return nullptr;  // string最后的','

        string nums;
        while (idx < data.size() && data[idx] != ',') {
            if (data[idx] == '-') // 负数
                nums += data[idx];
            else
                nums += to_string(data[idx] - '0');
            ++idx;  // 全局累加，遍历完整个string
        }

        int number = atoi(nums.c_str());
        TreeNode* node = new TreeNode(number);
        idx = idx + 1;
        node->left = restore();
        node->right = restore();
        return node;
    }
};