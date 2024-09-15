#include <vector>
using namespace std;

/*
88. 合并两个有序数组
https://leetcode-cn.com/problems/merge-sorted-array/

*/

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size() - 1;
        int i = m - 1;
        int j = n - 1;
        for (int k = m + n - 1; k >= 0; --k) {
            if (j < 0 || (i >= 0 && j >= 0 && nums1[i] >= nums2[j])) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};
