#include <vector>
using namespace std;

/*
410. 分割数组的最大值
https://leetcode-cn.com/problems/split-array-largest-sum/

求解：最小化 “m个子数组各自和最大值”。分m段，怎么分，这个问题很难
判定：给定一个数值T，“m个子数组各自和<=T”是否合法
      就是说，“能否将nums分成m个连续子数组，每组的和最大值<=T”
      转化为，有容积为T的盒子，问m个这样的盒子能不能把这个数组装下（m是题目给定的）
每组的和最大值，意思就是要能塞进盒子，每组之和不能超过这个盒子体积的大小
这个T有个最小值。当T很小的时候，m会比给定的大，不符合要求。当T很大的时候，m可以变小，那本来一个盒子就能装下的，硬是拆成m个盒子，也是可以的。
所以T的解空间具有特殊的单调性（单调分段0/1函数），T>=一个值才合法。这个值就是题目要求的
*/

class Solution {
   public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for (int& num : nums) {
            left = max(left, num);  // 盒子的最小体积，得把最大的那个装下
            right += num;  // 盒子的最大体积，所有之和，这个一个盒子就好
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (validate(nums, m, mid)) {
                right = mid;  // 要求的是mid的最小值
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

   private:
    bool validate(vector<int>& nums, int m, int size) {
        int boxV = 0;
        int boxN = 1;
        for (int& num : nums) {
            if (boxV + num <= size) {
                // 当前盒子还塞得下
                boxV += num;
            } else {
                // 当前盒子塞不下了，要新开一个盒子
                boxV = num;
                boxN += 1;
            }
        }
        return boxN <= m;
    }
};