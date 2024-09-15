#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
911. 在线选举
https://leetcode.cn/problems/online-election/

*/

struct Node {
    int times;     // 要排序的key1: 总共投票数
    int lasttime;  // 要排序的key2: 最近一次的次数
    int person;    // 附加信息
    Node(int person, int times, int lasttime) : times(times), lasttime(lasttime), person(person) {}
};

bool operator<(const Node& a, const Node& b) {
    // top出来的是b，因为默认是最大堆
    return (a.times < b.times) || (a.times == b.times && a.lasttime < b.lasttime);
}

class TopVotedCandidate {
   public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        n = times.size();
        this->times = times;
        priority_queue<Node> heap;
        unordered_map<int, int> h;  // {person: times}
        ansList = vector<int>(n, 0);

        // 最大堆
        for (int i = 0; i < n; ++i) {
            int person = persons[i];
            if (h.find(person) == h.end()) {
                heap.push(Node(person, 1, i));
                h[person] = 1;
            } else {
                heap.push(Node(person, h[person] + 1, i));
                h[person] += 1;
            }

            Node htop = heap.top();
            ansList[i] = htop.person;
        }
    }

    int q(int t) {
        // 在times里面找，小于等于t的最大值下标
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (times[mid] <= t)
                left = mid;
            else
                right = mid - 1;
        }
        return ansList[right];
    }

   private:
    int n;
    vector<int> times;
    vector<int> ansList;
};
