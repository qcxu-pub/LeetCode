#include <queue>
#include <vector>
using namespace std;

/*
973. 最接近原点的 K 个点
https://leetcode-cn.com/problems/k-closest-points-to-origin/

思路同23+703
*/

struct Node {
    int dist;           // 要排序的key
    vector<int> point;  // 附加信息
    Node(int distance, vector<int> point) : dist(distance), point(point) {}
};

bool operator<(const Node& a, const Node& b) {
    return a.dist < b.dist;
}

class Solution {
   public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int k) {
        this->k = k;
        for (vector<int>& point : points) {
            add(point);
        }
        
        vector<vector<int> > ans;
        while (!q.empty()) {
            ans.push_back(q.top().point);
            q.pop();
        }
        return ans;
    }

   private:
    int k;
    priority_queue<Node> q;

    int getDist(vector<int>& p) {
        int x = p[0];
        int y = p[1];
        return x * x + y * y;
    }

    void add(vector<int>& point) {
        if (q.size() < k) {
            q.push(Node(getDist(point), point));
            return;
        }

        vector<int> topPoint = q.top().point;
        if (q.size() >= k && getDist(topPoint) >= getDist(point)) {
            q.pop();
            q.push(Node(getDist(point), point));
        }
    }
};