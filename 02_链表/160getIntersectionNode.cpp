/*
160. 相交链表
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};