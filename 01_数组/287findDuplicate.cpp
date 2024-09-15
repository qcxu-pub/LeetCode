#include <vector>
using namespace std;

/*
287. 寻找重复数
https://leetcode-cn.com/problems/find-the-duplicate-number/

思路：本题一个特别的地方：nums[i]的值域范围在[1,n]之间。所以nums[i]合法，nums[nums[i]]合法。
本题一定有1个重复的元素，要找到重复的元素是什么
所以要在数组上实现快慢指针，环开始的地方，就是重复元素的地方
坑: 不能直接写while(fast!=slow)，不然都进不了while循环
*/

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        // 相遇点
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
                break;
        }
        // 找环开始的地方
        int finder = 0;
        while (true) {
            finder = nums[finder];
            slow = nums[slow];
            if (finder == slow)
                break;
        }
        return finder;
    }
};