#include <queue>
#include <vector>
using namespace std;

/*
215. 数组中的第K个最大元素
https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

思路同703

时间复杂度: O(nlogk)
*/

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k;
        for (int& num : nums) {
            add(num);
        }
        return q.top();
    }

   private:
    int k;
    priority_queue<int, vector<int>, greater<int> > q;

    void add(int val) {
        if (q.size() < k)
            q.push(val);
        else if (q.size() >= k && val > q.top()) {
            q.pop();
            q.push(val);
        }
    }
};