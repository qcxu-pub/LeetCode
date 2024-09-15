#include <queue>
#include <vector>
using namespace std;

/*
207. 课程表
https://leetcode-cn.com/problems/course-schedule/

拓扑序，就是按这个顺序访问：访问该点的时候，之前的都访问过了。就像本题的先修课程。
从哪个点开始出发？从没有先修课的那些课开始！也就是，入度为0的那些课程开始遍历。
*/

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        return lessons.size() == numCourses;
    }

   private:
    vector<vector<int>> to;
    vector<int> inDeg;
    queue<int> q;
    vector<int> lessons;
};