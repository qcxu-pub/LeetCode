#include <vector>
#include <queue>
using namespace std;
#include "stdlib.h"

/*
912. 排序数组
https://leetcode-cn.com/problems/sort-an-array/

该题尝试各种排序算法
*/


/*
归并排序。重点。
稳定排序。时间复杂度O(nlogn)
*/
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

   private:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void merge(vector<int>& a, int left, int mid, int right) {
        // [left, mid], [mid + 1, right]

        if (left > right)
            return;

        int n = right - left + 1;
        vector<int> temp(n, 0);
        int i = left;
        int j = mid + 1;
        for (int k = 0; k < n; ++k) {
            // j出界；或者都在范围里，谁小要谁
            if (j > right || (i <= mid && a[i] < a[j]))
                temp[k] = a[i++];
            // i出界；或者都在范围里，谁大要谁
            else
                temp[k] = a[j++];
        }

        // copy回原数组
        for (int k = 0; k < n; ++k) {
            a[left + k] = temp[k];
        }
    }
};


/*
堆排序。重点。
代码最短。时间复杂度O(nlogn)
*/
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> q;
        // 默认大顶堆。所以里面可以求负存放拿取，这样可以实现小顶堆的效果
        for (int& num : nums) {
            q.push(-num);
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = -1 * q.top();
            q.pop();
        }
        return nums;
    }
};

/*
快速排序。重点。
跑的最快。时间复杂度O(nlogn)
*/
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

   private:
    void quickSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot);
        quickSort(arr, pivot + 1, right);
    }

    int partition(vector<int>& a, int left, int right) {
        int pivot = left + rand() % (right - left + 1);
        int pivotVal = a[pivot];
        while (left <= right) {
            while (a[left] < pivotVal)
                ++left;
            while (a[right] > pivotVal)
                --right;
            if (left == right) {
                break;
                // int temp = a[left];
                // a[left] = a[pivot];
                // a[pivot] = temp;
            }
            if (left < right) {
                int temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                ++left;
                --right;
            }
        }
        return right;
    }
};


/*插入排序 -- 超时*/
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        insert_sort(nums);
        return nums;
    }

   private:
    void insert_sort(vector<int>& arr) {
        for (int i = 1; i < arr.size(); ++i) {
            int temp = arr[i];
            int j;
            // i前面的是已经排好序的。新元素插入合适位置
            for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
};


/*冒泡排序 -- 超时*/
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        bubble_sort(nums);
        return nums;
    }

   private:
    void bubble_sort(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            // 最大的排在末尾了，末尾已经有序了
            for (int j = 0; j < arr.size() - 1 - i; ++j) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
};


/*选择排序 -- 超时*/
class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int minIdx = i;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] < nums[minIdx])
                    minIdx = j;
            }
            // 把最小值换到当前位置
            int temp = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = temp;
        }
        return nums;
    }
};
