/*
21. 合并两个有序链表
https://leetcode-cn.com/problems/merge-two-sorted-lists/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans = ListNode(); // 保护结点
        ListNode* head = &ans;
        while (l1 != nullptr || l2 != nullptr) {
            if (l2 == nullptr || (l1 != nullptr && l2 != nullptr && l1->val <= l2->val)) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        return ans.next;
    }
};