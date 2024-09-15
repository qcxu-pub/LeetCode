#include <unordered_map>
using namespace std;

/*
146. LRU 缓存
https://leetcode-cn.com/problems/lru-cache/

思路：
1.要线性表（数组或链表），按时间排
2.要支持：头部插入；尾部删除；访问元素是否在线性表中，中间删除
3.头部尾部的插入删除，中间删除 --> 链表在任意位置插删更高效
4.访问元素是否在链表中，但链表查询很慢。用 hashmap 映射，key为数值，value指向链表结点

结论：实现LRU，用 无序映射 + 双向链表
*/

class LRUCache {
   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        // 保护结点
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            Node* curr = hashMap[key];
            // cout << "get: key=" << key << ", value=" << hashMap[key]->value
            // << endl;
            deleteNode(curr);
            insertNode(head, curr);
            return curr->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            Node* curr = hashMap[key];
            curr->value = value;
            deleteNode(curr);
            insertNode(head, curr);
        } else {
            if (hashMap.size() >= capacity) {
                deleteNode(tail->pre);
            }
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            insertNode(head, newNode);
        }
        // cout << "put: key=" << key << ", value="<< hashMap[key]->value <<
        // endl;
    }

   private:
    struct Node {
        int key;
        int value;
        Node* pre;
        Node* next;
    };
    unordered_map<int, Node*> hashMap;

    int capacity;
    Node* head;
    Node* tail;

    // 在链表头部增加结点node
    void insertNode(Node* pHead, Node* node) {
        node->next = pHead->next;
        node->pre = pHead;
        pHead->next->pre = node;
        pHead->next = node;
        hashMap[node->key] = node;
    }

    // 删除结点node
    void deleteNode(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        hashMap.erase(node->key);
        // delete node;  // 不能把node的内存释放掉啊。很多是更新结点位置用的。
    }
};