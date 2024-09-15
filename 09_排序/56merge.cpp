#include <vector>
#include <algorithm>
using namespace std;

/*
56. 合并区间
https://leetcode-cn.com/problems/merge-intervals/

*/


/*
解法1
对区间进行双关键字排序（左右端点）
然后判断当前能到达的最远位置，进行区间合并
*/

class Solution {
   public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        // lambda表达式
        sort(intervals.begin(), intervals.end(),
             [&](vector<int>& a, vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
             });
        // 当前最远可以到的位置
        vector<vector<int> > ans;
        int start = -1;
        int farthest = -1;
        for (vector<int>& interval : intervals) {
            int x = interval[0];
            int y = interval[1];
            // 跟之前的重叠
            if (farthest >= x) {
                farthest = max(farthest, y);
            }
            // 跟之前没有重叠，新的开始
            else {
                if (farthest != -1) {
                    ans.push_back({start, farthest});
                }
                start = x;
                farthest = y;
            }
        }
        ans.push_back({start, farthest});
        return ans;
    }
};


/*
解法2
差分思想，把区间造成影响覆盖的问题变为关键事件。用批处理的方式扫一遍就能看到影响
把每个区间[l,r]看做一次+1覆盖，进而转化为 l处+1，r+1处-1，这两个事件
把2n个事件排序、扫描，用一个计数变量记录覆盖次数，0->1 / 1->0，就是合并后的区间端点
细节：排序是按key主排序，按-1->1次排序。比如：[1,3][4,5]
*/

class Solution {
   public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        // 生成事件
        vector<pair<int, int> > events;
        for (vector<int>& interval : intervals) {
            events.push_back({interval[0], 1});
            events.push_back({interval[1] + 1, -1});
        }
        sort(events.begin(), events.end());

        int record = 0;
        int start = 0;
        vector<vector<int> > ans;
        // 批处理
        for (pair<int, int>& event : events) {
            // 如果record上来就是0，这一段一定是刚开始
            if (record == 0) {
                start = event.first;
            }
            record += event.second;
            // 如果事件操作后记录为0，说明这一段一定是结尾
            if (record == 0) {
                ans.push_back({start, event.first - 1});
            }
        }
        return ans;
    }
};