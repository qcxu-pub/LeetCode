#include <vector>
#include <unordered_map>
using namespace std;

/*
169. 多数元素
https://leetcode-cn.com/problems/majority-element/

*/

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        for (int n : nums) {
            if (h.find(n) == h.end())
                h[n] = 1;
            else
                h[n]++;
        }

        int ans;
        for (auto h1 : h) {
            int num = h1.first;
            int cnt = h1.second;
            if (cnt > nums.size() / 2) {
                ans = num;
                break;
            }
        }
        return ans;
    }

   private:
    unordered_map<int, int> h;
};