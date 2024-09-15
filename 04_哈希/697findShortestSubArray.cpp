#include <unordered_map>
#include <vector>
using namespace std;

/*
697. 数组的度
https://leetcode-cn.com/problems/degree-of-an-array/

*/

class Solution {
   public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        int minLen = 50001;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (h.find(num) != h.end()) {
                h[num][0] += 1;
                h[num][2] = i;
            } else {
                h[num] = {1, i, i};
            }
        }
        for (auto& kv : h) {
            int k = kv.first;
            vector<int> v = kv.second;
            if (v[0] > degree) {
                degree = v[0];
                minLen = v[2] - v[1] + 1;
            } else if (v[0] == degree) {
                minLen = min(minLen, v[2] - v[1] + 1);
            }
        }
        return minLen;
    }

   private:
    unordered_map<int, vector<int> > h;
};