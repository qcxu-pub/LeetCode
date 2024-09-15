#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

/*
347. 前 K 个高频元素
https://leetcode.cn/problems/top-k-frequent-elements/

*/

struct Node {
    int key; // 按key排序，词频
    int val; // 具体是哪个数
    Node(int key, int val) : key(key), val(val) {}
};

bool operator< (const Node& a, const Node& b) {
    return a.key > b.key;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计词频
        for (int& num : nums)
            h[num]++;
        
        // 小顶堆，堆元素个数为k
        // 新来的元素比堆顶更大，就把堆顶替换掉    
        for (auto& h1 : h) {
            int num = h1.first;
            int freq = h1.second;
            // if (!q.empty())
            //     cout << "q.top.num=" << q.top().val << ",q.top.freq=" << q.top().key << ",curr num=" << num << ",curr freq=" << freq << endl;
            if (q.size() < k)
                q.push(Node(freq, num));
            else if (q.size() >= k && q.top().key < freq) {
                q.pop();
                q.push(Node(freq, num));
            }
        }
        // 答案
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top().val);
            q.pop();
        }
        return ans;
    }

    private:
    unordered_map<int,int> h;
    priority_queue<Node> q;

};