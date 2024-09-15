#include <vector>
using namespace std;

/*
1248. 统计最美子数组
https://leetcode-cn.com/problems/count-number-of-nice-subarrays/

思路：
子段奇数的数量为k
--> 奇数1/偶数0，子段和为k，sum(l,r) = k = s[r] - s[l-1]
--> 两数之差问题 s[j] = s[i] - k
*/

class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1] % 2;
        }

        int ans = 0;
        // key:i, value: count[i]
        vector<int> count(n + 1);
        count[s[0]]++;
        for (int i = 1; i <= n; ++i) {
            if (s[i] - k >= 0)
                ans += count[s[i] - k];
            count[s[i]]++;
        }
        return ans;
    }
};