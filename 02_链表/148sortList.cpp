#include <algorithm>
#include <vector>
using namespace std;

/*
148. 排序链表
https://leetcode-cn.com/problems/sort-list/
*/


/*利用vector*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Rule {
    bool operator()(ListNode* node1, ListNode* node2) const {
        return (node1->val) < (node2->val);
    }
};

class Solution {
   public:
    vector<ListNode*> vec;
    ListNode* sortList(ListNode* head) {
        ListNode* t = head;
        while (t != nullptr) {
            vec.push_back(t);
            t = t->next;
        }
        if (vec.size() == 0) {
            return head;
        }
        sort(vec.begin(), vec.end(), Rule());

        ListNode* headNew = vec[0];
        head = headNew;
        for (int i = 1; i < vec.size(); ++i) {
            head->next = vec[i];
            head = head->next;
        }
        head->next = nullptr;
        return headNew;
    }
};


/*自顶向下归并排序
时间复杂度O(nlogn)，空间复杂度O(logn)，n是链表长度
*/
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        return sort(head, nullptr);
    }

private:
    ListNode* sort(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        // 找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return mergeTwoLists(sort(head, mid), sort(mid, tail));
    }

    // 21题
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


/*自底向上归并排序
时间复杂度O(nlogn)，空间复杂度O(1)
*/
class Solution3 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }

        ListNode* dummyHead = new ListNode(0, head);
        // 双倍长度的子链表合并
        for (int subLength=1; subLength < length; subLength=subLength*2) {
            ListNode* prev = dummyHead;
            ListNode* curr = dummyHead->next;
            while (curr != nullptr) {
                // 以head1为头，长度subLength的链表
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; ++i) {
                    curr = curr->next;
                }
                // 以head2为头，长度subLength的链表
                ListNode* head2 = curr->next;
                curr->next = nullptr; // head1链表结束
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; ++i) {
                    curr = curr->next;
                }
                // 迭代结束指针要移到next的地方
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr; // head2链表结束
                }
                // 合并head1子链表和head2子链表
                ListNode* merged = mergeTwoLists(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

private:
    // 21题
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