#include <deque>
#include <vector>
#include <queue>
using namespace std;

/*
239. 滑动窗口最大值
https://leetcode-cn.com/problems/sliding-window-maximum/

思路1：优先队列（堆），因为要求max，就是取堆顶。但要实现懒惰删除法，因为优先队列还不支持删除堆中的任意元素。
       懒惰删除法具体做法是：当过了滑动窗口的元素不影响结果的时候，就先不动他；但一旦它成为堆顶，就先检查它的下标是否在滑动窗口范围里面，不在就pop掉。这样可以保证始终在堆顶操作。
       懒惰体现在，删 不是每次滑过后即使发生的，而是当 不删 影响到结果的时候才开始做
思路2：单调队列，队列max长度固定。窗口里面靠左的更小的值，永无出头之日。
*/


/*优先队列*/
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            q.push({nums[i], i});
            if (i >= k - 1) {
                // 要 [i-k+1,i] 这一段窗口
                while (q.top().second < i - k + 1)
                    q.pop();
                ans.push_back(q.top().first);
            }
        }
        return ans;
    }

   private:
    priority_queue<pair<int, int> > q;  // <值，下标>
};


/*单调队列*/
class Solution2 {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }

   private:
    deque<int> q;  // 存放的是下标i，ans = {nums[q.front()]}
};