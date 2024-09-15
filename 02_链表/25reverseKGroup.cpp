/*
25. K 个一组翻转链表
https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

划重点: 重点关注每组的头。preGroupHead, head, nextGroupHead
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* preGroupHead = nullptr;
        ListNode* HeadNew = getEnd(head, k);
        HeadNew = HeadNew == nullptr ? head : HeadNew;

        while (head != nullptr) {
            ListNode* end = getEnd(head, k);
            if (end == nullptr) {
                preGroupHead->next = head;
                break;
            }

            ListNode* newGroupHead = end->next;
            reverseList(head, newGroupHead);
            if (preGroupHead != nullptr) {
                preGroupHead->next = end;
            }
            head->next = newGroupHead;
            preGroupHead = head;
            head = newGroupHead;
        }
        return HeadNew;
    }

   private:
    ListNode* getEnd(ListNode* head, int k) {
        ListNode* headCpy = head;
        int i = 1;
        while (i < k && headCpy != nullptr) {
            headCpy = headCpy->next;
            i++;
        }
        // if (headCpy == nullptr)
        //     return nullptr;
        // else
        //     return headCpy;
        return headCpy;
    }

    void reverseList(ListNode* head, ListNode* stop) {
        ListNode* headCpy = head;
        ListNode* last = nullptr;
        while (headCpy != stop) {
            ListNode* nextHead = headCpy->next;
            headCpy->next = last;
            last = headCpy;
            headCpy = nextHead;
        }
    }
};