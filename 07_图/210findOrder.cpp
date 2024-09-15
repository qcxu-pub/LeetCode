#include <queue>
#include <vector>
using namespace std;

/*
210. 课程表 II
https://leetcode-cn.com/problems/course-schedule-ii/

跟207是一样的。只是返回值不一样罢了
*/

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建图，初始化出边数组
        to.resize(numCourses, vector<int>());
        inDeg.resize(numCourses, 0);
        for (vector<int>& prerequisite : prerequisites) {
            int ai = prerequisite[0];
            int bi = prerequisite[1];
            to[bi].push_back(ai);
            inDeg[ai] += 1;
        }

        // 拓扑排序第1步：入度为0的，入队
        for (int i = 0; i < numCourses; ++i) {
            if (inDeg[i] == 0)
                q.push(i);
        }

        // bfs
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x);

            // 拓扑排序第2步：扩展一个点，周围点入度-1
            for (int y : to[x]) {
                inDeg[y]--;
                // 拓扑排序第3步：入度为0的，说明先修课程已经都修完了，可以入队了
                if (inDeg[y] == 0)
                    q.push(y);
            }
        }
        if (lessons.size() == numCourses)
            return lessons;
        else
            return vector<int>();
    }

   private:
    vector<vector<int>> to;
    vector<int> inDeg;
    queue<int> q;
    vector<int> lessons;
};