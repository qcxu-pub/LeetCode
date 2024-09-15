/*
面试题 04.06. 后继者
https://leetcode-cn.com/problems/successor-lcci/

二叉搜索树求前驱/后继
1.前驱就是找小于val的最大结点，在val为根的左子树一路往右走到底；如果没有左子树，那就在走之前走过点中的一个
2.后继就是找大于val的最小结点，在val为根的右子树一路往左走到底；如果没有右子树，那就在之前走过点中的一个
所以先查找val
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return getNext(root, p->val);
    }

    // 写一个更通用的
    TreeNode* getNext(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        TreeNode* curr = root;
        while (curr != nullptr) {
            // 如果找到相等的val，那比val大的的最小值在右子树一路往左到底
            if (curr->val == val) {
                if (curr->right != nullptr) {
                    ans = curr->right;
                    while (ans->left != nullptr)
                        ans = ans->left;
                }
                break;
            }
            // 如果最后没找到val，那答案在这里产生。每一步记录结果
            if (curr->val > val) {
                if (ans == nullptr || ans->val > curr->val)
                    ans = curr;
                curr = curr->left;
                continue;
            } else {
                curr = curr->right;
            }
        }
        return ans;
    }
};