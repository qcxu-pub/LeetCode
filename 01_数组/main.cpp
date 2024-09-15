#include <cstdio>
#include <iostream>

/*
#include "88merge.cpp"
int main() {
    Solution solu;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    solu.merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << ",";
    }
    return 0;
}
*/

/*
#include "283moveZeroes.cpp"
int main() {
    Solution solu;
    vector<int>nums = {0,1,0,3,12};  // case1
    // vector<int>nums = {0};  // case2
    solu.moveZeroes(nums);
    for (int num : nums) {
        cout << num << ",";
    }
    return 0;
}
*/

/*
#include "26removeDuplicates.cpp"
int main() {
    Solution solu;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = solu.removeDuplicates(nums);
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << ",";
    }
    return 0;
}
*/

/*
#include "1248numberOfSubarrays.cpp"
int main() {
    Solution solu;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << solu.numberOfSubarrays(nums, k);
}
*/

/*
#include "1109corpFlightBookings.cpp"
int main() {
    Solution solu;
    int n = 5;
    vector<vector<int> > bookings = {{1,2,10},{2,3,20},{2,5,25}};
    vector<int> ans = solu.corpFlightBookings(bookings, n);
    for (int& a: ans)
        cout << a << endl;
}
*/

/*
#include "66plusOne.cpp"
int main() {
    Solution solu;
    // vector<int> digits = {1,2,3};
    vector<int> digits = {9,8,7,6,5,4,3,2,1,0};
    vector<int> ans = solu.plusOne(digits);
    for (int& a: ans)
        cout << a << endl;
}
*/

/*
#include "1twoSum.cpp"
int main() {
    Solution solu;
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> ans = solu.twoSum(nums, target);
    for (int& a: ans)
        cout << a << ",";
}
*/

/*
#include "75sortColors.cpp"
int main() {
    Solution solu;
    vector<int> nums = {2,0,2,1,1,0};
    solu.sortColors(nums);
    for(int n: nums)
        cout << n << ",";
}
*/

/*
#include "75sortColors.cpp"
int main() {
    Solution solu;
    // vector<int> nums = {2,0,2,1,1,0};
    vector<int> nums = {1,2,0};
    solu.sortColors(nums);
    for (int& n: nums)
        cout << n << ",";
}
*/

#include "76minWindow.cpp"
int main() {
    Solution solu;
    // string s = "ADOBECODEBANC";
    // string t = "ABC";

    // string s = "abc";
    // string t = "b";

    string s = "a";
    string t = "aa";
    cout << solu.minWindow(s, t);
}