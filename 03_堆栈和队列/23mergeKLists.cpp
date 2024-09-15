#include <queue>
#include <vector>
using namespace std;

/*
23. 合并K个升序链表
https://leetcode-cn.com/problems/merge-k-sorted-lists/

思路1：用 priority_queue 解决
思路2：用分治解决，合并 k/2 个升序链表
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Node {
    int key;             // 用于排序的key
    ListNode* listNode;  // 其他附带信息
    Node(int key, ListNode* listNode) : key(key), listNode(listNode) {}
};


/*利用自带的 priority_queue库 做这个题目*/

bool operator<(const Node& a, const Node& b) {
    return a.key > b.key;
}

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (ListNode* head : lists) {
            while (head != nullptr) {
                q.push(Node(head->val, head));
                head = head->next;
            }
        }

        ListNode ans = ListNode();  //保护结点
        ListNode* head = &ans;
        while (!q.empty()) {
            head->next = q.top().listNode;
            q.pop();
            head = head->next;
        }
        head->next = nullptr;
        return ans.next;
    }

   private:
    priority_queue<Node> q;
};


/*自己写一个二叉堆，实现 priority_queue*/

class BinaryHeap {
public:
    BinaryHeap() {
        // 从1开始计数
        heap.push_back(Node(0, nullptr));
    }

    bool empty() {
        return heap.size() == 1;
    }

    // top
    Node getMin() {
        return heap[1];
    }

    // push: 先push_back到vector，然后小的向上调整
    void insert(const Node& node) {
        heap.push_back(node);
        heapifyUp(heap.size() - 1);
    }

    // pop: 把vector里的最后一个元素提到根节点，然后把它向下调整
    void deleteMin() {
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(1);
    }

private:
    vector<Node> heap;

    void heapifyUp(int p) {
        while (p > 1) {
            int father = p/2;
            if (heap[p].key < heap[father].key) {
                swap(heap[p], heap[father]);
                p /= 2;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int p) {
        while (p * 2 < heap.size()) {
            int lchild = p * 2;
            int rchild = p * 2 + 1;
            int chosen = lchild;
            if (rchild < heap.size() && heap[lchild].key > heap[rchild].key)
                chosen = rchild;

            if (heap[p].key > heap[chosen].key) {
                swap(heap[p], heap[chosen]);
                p = chosen;
            } else {
                break;
            }
        }
    }
};
 
class Solution2 {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (ListNode* head : lists) {
            while (head != nullptr) {
                q.insert(Node(head->val, head));
                head = head->next;
            }
        }

        ListNode ans = ListNode();  //保护结点
        ListNode* head = &ans;
        while (!q.empty()) {
            head->next = q.getMin().listNode;
            q.deleteMin();
            head = head->next;
        }
        head->next = nullptr;
        return ans.next;
    }

   private:
    BinaryHeap q;
};
