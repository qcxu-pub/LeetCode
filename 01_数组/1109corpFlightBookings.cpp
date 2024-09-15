#include <vector>
using namespace std;

/*
1109. 航班预订统计
https://leetcode-cn.com/problems/corporate-flight-bookings/

思路：给子段统一加一个数。用差分。
*/


class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int> >& bookings, int n) {
        vector<int> delta(n + 2, 0);
        for (vector<int>& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            delta[first] += seats;
            delta[last + 1] -= seats;
        }

        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + delta[i];

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i)
            ans[i] = sum[i + 1];

        return ans;
    }
};