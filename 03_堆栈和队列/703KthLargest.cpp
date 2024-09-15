#include <queue>
#include <vector>
using namespace std;

/*
703. 数据流中的第 K 大元素
https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/

思路：要第k大，所以是小顶堆，堆元素的总个数为k，这样取堆顶就是第k大。
如果新进来的元素比堆顶小，那么这个新元素一定是第k+n大，所以可以忽略不加入堆；
如果新进来的元素比堆顶大，那么堆顶元素就成了k+1大，所以把堆顶pop掉，新元素加入。

时间复杂度: O(nlogk)
*/

class KthLargest {
   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums)
            add(num);
    }

    int add(int val) {
        if (q.size() < k) {
            q.push(val);
        } else if (q.size() >= k && val > q.top()) {
            q.pop();
            q.push(val);
        }
        return q.top();
    }

   private:
    int k;
    priority_queue<int, vector<int>, greater<int> > q;
};