/*
24. 两两交换链表中的节点
https://leetcode-cn.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode ans = ListNode(); // 保护节点
        ListNode* last = &ans;
        ListNode* nextNode;
        ListNode* nextHead;
        while (head != nullptr) {
            nextNode = head->next;
            if (nextNode == nullptr) {
                last->next = head;
                last = last->next;
                break;
            }
            last->next = nextNode;
            nextHead = nextNode->next;
            nextNode->next = head;
            last = head;
            head = nextHead;
        }
        last->next = nullptr;

        return ans.next;
    }
};