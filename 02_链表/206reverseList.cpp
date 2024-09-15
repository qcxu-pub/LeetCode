/*
206. 反转链表
https://leetcode-cn.com/problems/reverse-linked-list/
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        while (head != nullptr) {
            ListNode* nexthead = head->next;
            head->next = last;
            last = head;
            head = nexthead;
        }
        return last;
    }
};