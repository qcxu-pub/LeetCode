/*
136. 邻值查找
https://www.acwing.com/problem/content/138/
*/

#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int val;
    int idx;
    Node* pre;
    Node* next;
};

const int SIZE = 1e5 + 1;
int a[SIZE], ans[SIZE], rk[SIZE];
Node* pos[SIZE];
int n;

// 在node后面增加一个结点，val=a[idx]
Node* addNode(Node* node, int idx) {
    Node* newNode = new Node();
    newNode->val = a[idx];
    newNode->idx = idx;
    newNode->next = node->next;
    newNode->pre = node;
    node->next->pre = newNode;
    node->next = newNode;
    return newNode;
}

// 删除node结点
void deleteNode(Node* node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        rk[i] = i;
    }
    // lambda表达式：对[rk+1,rk+n+1)进行排序。排序规则：使a[rk[·]]升序排序
    // mapping关系: rk[新序号] = 老序号
    // 老序号是题目给的，新序号是值在数组a中的大小排位
    sort(rk + 1, rk + n + 1, [&](int rki, int rkj) { return a[rki] < a[rkj]; });

    // 构建有序的双向链表
    Node head;  // 保护结点，符合大小顺序，且相邻差值要最大
    Node tail;  // 保护结点
    head.val = a[rk[1]] - 1e9;
    head.next = &tail;
    tail.val = a[rk[n]] + 1e9;
    tail.pre = &head;
    // 遍历新序号i，保存在老序号位置rk[i]。在tail.pre结点后面，新增a[rk[i]]结点
    for (int i = 1; i <= n; ++i) {
        pos[rk[i]] = addNode(tail.pre, rk[i]);
    }

    // 遍历老序号。因为1<=j<=i，所以从后往前算
    for (int i = n; i > 1; --i) {
        Node* curr = pos[i];
        if (a[i] - curr->pre->val <= curr->next->val - a[i])
            ans[i] = curr->pre->idx;
        else
            ans[i] = curr->next->idx;
        deleteNode(curr);
    }

    // 输出答案
    for (int i = 2; i <= n; ++i) {
        cout << "i=" << i << ",a[i]=" << a[i] << ",ans[i]=" << ans[i] << ",a[ans[i]]=" << a[ans[i]] << endl;
        // cout << abs(a[i] - a[ans[i]]) << " " << ans[i] << endl;
    }
    return 0;
}