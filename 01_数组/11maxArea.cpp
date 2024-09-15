#include <vector>
using namespace std;

/*
11. 盛最多水的容器
https://leetcode-cn.com/problems/container-with-most-water/

还是两端点问题。两重循环。优化就是去掉其中一重循环
多出来的那重循环冗余在哪里？area = min(a[i],a[j]) * (j-i)
a[i],a[j]中短的那个这次遍历完就没用了，因为用双指针遍历到(i,j)的时候，j-i已经是最大了
--> 两个指针从头尾向中间移动，谁短缩谁
*/

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
