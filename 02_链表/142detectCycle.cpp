/*
142. 环形链表 II
https://leetcode-cn.com/problems/linked-list-cycle-ii/
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* meet = hasCycle(head);
        if (meet == nullptr) {
            return nullptr;
        }
        while (head != meet) {
            head = head->next;
            meet = meet->next;
        }
        return head;
    }

   private:
    ListNode* hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr && slow != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return fast;
            }
        }
        return nullptr;
    }
};