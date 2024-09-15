#include <vector>
#include <unordered_set>
using namespace std;

/*
128. 最长连续序列
https://leetcode.cn/problems/longest-consecutive-sequence/

类似于双指针。在set上做
*/

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        //
        unordered_set<int> s;
        for (int& num : nums)
            s.insert(num);

        //
        int ans = 0;
        while (!s.empty()) {
            int curr = *(s.begin());
            int prev = curr - 1;
            int next = curr + 1;
            s.erase(curr);

            while (s.find(prev) != s.end()) {
                s.erase(prev);
                prev--;
            }
            while (s.find(next) != s.end()) {
                s.erase(next);
                next++;
            }

            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};