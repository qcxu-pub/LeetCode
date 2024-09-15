#include <stack>
#include <vector>
using namespace std;

/*
42. 接雨水
https://leetcode-cn.com/problems/trapping-rain-water/

*/

// 单调栈，单调递减，因为柱子一高就把水截了，就好算之前的情况了。横条子算面积。
class Solution {
   public:
    int trap(vector<int>& heights) {
        int ans = 0;
        for (int height : heights) {
            int accumulatedWidth = 0;
            while (!stk.empty() && height > stk.top().height) {
                int currentHeight = stk.top().height;
                accumulatedWidth += stk.top().width;
                stk.pop();
                if (!stk.empty()) {
                    int leftHeight = stk.top().height;
                    ans += accumulatedWidth * (min(leftHeight, height) - currentHeight);
                }
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


// 前缀max/后缀max。当前的高度=min(max(左边),max(右边))。竖条子算面积
class Solution2 {
   public:
    int trap(vector<int> heights) {
        int n = heights.size();
        preMax = vector<int>(n);
        sufMax = vector<int>(n);

        preMax[0] = heights[0];
        for (int i = 1; i < heights.size(); ++i)
            preMax[i] = max(preMax[i - 1], heights[i]);

        sufMax[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; --i)
            sufMax[i] = max(sufMax[i + 1], heights[i]);

        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            int up = min(preMax[i], sufMax[i]);
            int bottom = heights[i];
            ans += up - bottom;
        }
        return ans;
    }

   private:
    vector<int> preMax;
    vector<int> sufMax;
};