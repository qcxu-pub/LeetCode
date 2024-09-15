#include <cstdio>
#include <iostream>
using namespace std;

#include "703KthLargest.cpp"
int main() {
    int k = 3;
    vector<int> nums = {4,5,8,2};
    KthLargest* obj = new KthLargest(k, nums);
    cout << "after add 3: " << obj->add(3) << endl;
    cout << "after add 5: " << obj->add(5) << endl;
    cout << "after add 10: " << obj->add(10) << endl;
    cout << "after add 9: " << obj->add(9) << endl;
    cout << "after add 4: " << obj->add(4) << endl;
}

/*
#include "844backspaceCompare.cpp"
int main() {
    Solution solu;
    // string s = "ab#c";
    // string t = "ad#c";
    string s = "hd#dp#czsp#####";
    string t = "hd#dp#czsp######";
    cout << endl << solu.backspaceCompare(s,t);
}
*/

/*
#include "232MyQueue.cpp"
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << ",";
    obj->pop();
    cout << obj->empty() << ",";
}
*/

/*
#include "23mergeKLists.cpp"
int main() {
    ListNode* l13 = new ListNode(5, nullptr);
    ListNode* l12 = new ListNode(4, l13);
    ListNode* l11 = new ListNode(1, l12);

    ListNode* l23 = new ListNode(4, nullptr);
    ListNode* l22 = new ListNode(3, l23);
    ListNode* l21 = new ListNode(1, l22);

    ListNode* l32 = new ListNode(6, nullptr);
    ListNode* l31 = new ListNode(2, l32);

    vector<ListNode*> vec;
    vec.push_back(l11);
    vec.push_back(l21);
    vec.push_back(l31);

    Solution solu;
    ListNode* ans = solu.mergeKLists(vec);
    while (ans != nullptr) {
        cout << ans->val << ",";
        ans = ans->next;
    }
    return 0;
}
*/

/*
#include "20isValid.cpp"
int main() {
    // string s = "()";
    string s = "(]";
    Solution solu;
    cout << solu.isValid(s);
}
*/

/*
#include "155MinStack.cpp"
int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
}
*/

/*
#include "150evalRPN.cpp"
int main() {
    // vector<string> tokens = {"2","1","+","3","*"};
    // vector<string> tokens = {"4","13","5","/","+"};
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution solu;
    cout << solu.evalRPN(tokens);
}
*/

/*
#include "224calculate.cpp"
int main() {
    // string s = "3+2*2";
    string s1 = "1-1+1";
    Solution solu;
    cout << solu.calculate(s1) << endl;

    // string s3 = "-2+1";
    string s3 = "2+(3*2+1)";
    Solution3 solu3;
    cout << solu3.calculate(s3) << endl;
}
*/

/*
#include "84largestRectangleArea.cpp"
int main() {
    vector<int> heights = {2,1,5,6,2,3};
    Solution solu;
    cout << solu.largestRectangleArea(heights);
}
*/

/*
#include "42trap.cpp"
int main() {
    // vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> heights = {4,2,0,3,2,5};
    Solution solu;
    cout << solu.trap(heights);
}
*/
