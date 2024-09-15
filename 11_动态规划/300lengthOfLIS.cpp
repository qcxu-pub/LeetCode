#include <vector>
using namespace std;
#include <cstdio>
#include <iostream>

/*
300. 最长递增子序列
https://leetcode-cn.com/problems/longest-increasing-subsequence/

从暴力搜索开始想它的状态空间。子集问题。时间复杂度: O(2^n)
定义当前选的子段chosen。当 nums[i]>chosen[-1] 的时候，把 nums[i] 拼接上去，然后 dfs 选下一个数字

[0,3,1,6,2,7]
选0? 0                                --> 0              --> 代表: 以0结尾，最长递增子序列长度=1
选3? 3  0,3                           --> 0,3            --> 代表: 以3结尾，最长递增子序列长度=2=1+1
选1? 1  0,1                           --> 0,1            --> 代表: 第1结尾，最长递增子序列长度=2=1+1
选6? 6  0,6  3,6  1,6  0,3,6  0,1,6   --> 0,1,6 / 0,3,6  --> 代表: 以6结尾，最长递增子序列长度=3=2+1
选2? 2  0,2  1,2  0,1,2               --> 0,1,2          --> 代表: 以2结尾，最长递增子序列长度=3=2+1
选7? ................................................... --> 代表：以7结尾，最长递增子序列长度=3+1=4

蛮力搜索就是遍历状态空间中所有可能的上升序列。但我们只关心：选了几个数？结尾的数是哪个？
所以，结尾数+最长长度，作为序列的代表。他们之间的推导关系，就是最优子结构
举个例子，a[0]=0, a[1]=3, a[2]=1, a[3]=6, a[4]=2, a[5]=7
f[4] = max(f[0],f[2]) + 1, a[4]=2 > a[2]=1 > a[0]=0

状态: f[i]表示，前i个数构成的，以a[i]为结尾的最长上升子序列的长度
状态转移方程: f[i] = max{f[j]}+1, 其中, j<=i, a[j]<a[i]
边界: f[i] = 1, 其中, 0 <= i < n
目标: max{f[i]}, 其中, 0 <= i < n

*/

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // 以nums[i]结尾的LIS，最短就是他自己本身
        vector<int> f(n, 1);
        // 要更新f[i]，看他之前的序列
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        // 全局的LIS
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};



/*
拓展: 打印方案。最长子序列是哪个？
*/

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);  // 以nums[i]结尾的LIS，最短就是他自己本身
        vector<int> pre(n, -1);  // 记录转移路径
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    pre[i] = j;  // 这里记录的是下标
                }
            }
        }
        // 全局LIS
        int ans = 0;
        int end = -1;
        for (int i = 0; i < n; ++i) {
            if (f[i] > ans) {
                ans = f[i];
                end = i;
            }
        }
        // 打印方案
        this->nums = nums;
        this->pre = pre;
        print(end);
        //
        return ans;
    }

   private:
    vector<int> nums;
    vector<int> pre;
    void print(int i) {
        // 递归边界
        if (pre[i] == -1) {
            cout << nums[i] << ",";
            return;
        }
        // 递归
        print(pre[i]);
        // 回溯的时候打印，或者再开一个vector保存答案
        cout << nums[i] << ",";
    }
};