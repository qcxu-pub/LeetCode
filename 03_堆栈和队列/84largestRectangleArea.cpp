#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
84. 柱状图中最大的矩形
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

单调栈，单调递增
*/


class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ans = 0;
        for (int height : heights) {
            int accumulatedWidth = 0;
            // 破坏单调性时，从后向前更新前面的ans，聚合替换之前的rect
            while (!stk.empty() && height < stk.top().height) {
                // cout << "---------- height=" << height << endl;
                // cout << stk.top().height << "," << stk.top().width << "," << accumulatedWidth << endl;

                accumulatedWidth += stk.top().width;
                ans = max(ans, accumulatedWidth * stk.top().height);
                stk.pop();
            }
            stk.push({height, accumulatedWidth + 1});
        }
        return ans;
    }

   private:
    struct Rect {
        int height;
        int width;
    };
    stack<Rect> stk;
};