#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

/*
874. 模拟行走机器人
https://leetcode-cn.com/problems/walking-robot-simulation/

思路：
1.如何判断是否有障碍物？ --> 用hash查找
2.怎么把二维坐标做hash？ --> 编码成string/二维转一维
3.左转右转怎么表示？ --> mod 4
4.网格行走类型题目技巧：方向数组
*/

class Solution {
   public:
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
        for (vector<int> obstacle : obstacles) {
            // obs1.insert(calcHash1(obstacle));
            obs2.insert(calcHash2(obstacle));
        }

        int ans = 0;
        int dir = 0;  // N:0, E:1, S:2, W:3
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0, y = 0;
        for (int command : commands) {
            if (command == -1)  // turn right
                dir = (dir + 1) % 4;
            else if (command == -2)  // turn left
                dir = (dir - 1 + 4) % 4;
            else {
                for (int i = 0; i < command; ++i) {
                    int tx = x + dx[dir];
                    int ty = y + dy[dir];
                    // if (obs1.find(calcHash1({tx, ty})) != obs1.end())
                    //     break;
                    if (obs2.find(calcHash2({tx, ty})) != obs2.end())
                        break;
                    x = tx;
                    y = ty;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }

   private:
    unordered_set<string> obs1;
    string calcHash1(vector<int> obstacle) {
        return to_string(obstacle[0]) + "+" + to_string(obstacle[1]);
    }

    unordered_set<long long> obs2;
    long long calcHash2(vector<int> obstacle) {
        return (obstacle[0] + 30000) * 60001ll + (obstacle[1] + 30000);
    }
};