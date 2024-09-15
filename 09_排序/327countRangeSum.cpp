#include <vector>
#include <unordered_set>
using namespace std;

/*
327. 区间和的个数
https://leetcode-cn.com/problems/count-of-range-sum/

思路同493。
区间和，用前缀和的差分。区间左右端点，用归并排序。

下面代码好像边界条件没过。。先这样吧。。
*/

class Solution {
   public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;

        // 要求子区间，所以算下前缀和
        int n = nums.size();
        preSum = vector<long long>(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        // cout << "preSum = ";
        // for (int s : preSum)
        //     cout << s << ",";
        // cout << endl;

        mergeSort(preSum, 0, preSum.size() - 1);
        return ans;
    }

   private:
    int lower, upper;
    int ans = 0;
    vector<long long> preSum;

    void mergeSort(vector<long long>& arr, int left, int right) {
        if (left > right)
            return;
        if (left == right) {
            calculate(arr, left, left, left);
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        calculate(arr, left, mid, right);
        merge(arr, left, mid, right);
    }

    void calculate(vector<long long>& a, int left, int mid, int right) {
        if (left == right && getRangePos(a[left]) == 0) {
            ans += 1;
            return;
        }

        for (int i = left; i <= mid; ++i) {
            int j = mid;
            int start = mid;
            while (j < right) {
                // cout << "getRangePos(a[j + 1] - a[i]) = " << a[j + 1] - a[i]
                // << endl; cout << a[j + 1] << "," << a[i] << ",";
                if (getRangePos(a[j + 1] - a[i]) < 0) {
                    start++;
                    j++;
                } else if (getRangePos(a[j + 1] - a[i]) == 0) {
                    j++;
                } else {
                    break;
                }
            }
            // cout << "i=" << i << ",j=" << j << ",start=" << start <<
            // ",j-start=" << j-start<< endl;
            ans += (j - start);
        }
    }

    int getRangePos(long long x) {
        if (x >= lower && x <= upper)
            return 0;
        else if (x < lower)
            return -1;
        else
            return 1;
    }

    void merge(vector<long long>& arr, int left, int mid, int right) {
        int n = right - left + 1;
        vector<long long> temp(n, 0);
        int i = left, j = mid + 1;
        for (int k = 0; k < n; ++k) {
            if (j >= right || (i <= mid && arr[i] < arr[j])) {
                temp[k] = arr[i];
                ++i;
            } else {
                temp[k] = arr[j];
                --j;
            }
        }
        for (int k = 0; k < n; ++k) {
            arr[left + k] = temp[k];
        }
    }
};