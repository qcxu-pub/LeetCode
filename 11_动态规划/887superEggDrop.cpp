#include <vector>
using namespace std;

/*
887. 鸡蛋掉落
https://leetcode-cn.com/problems/super-egg-drop/

状态: f[i,len]表示，当前有i个鸡蛋，测试的楼层总数是len，确定临界值的最小操作次数 (0<i<=k, 1<=len<=n)

决策: 在len的区间长度上找一个p，也就是去第p层扔鸡蛋，使期望的尝试次数最少
(跟312戳气球一样，先考虑两边的情况，再考虑本层逻辑：操作次数+1)
1.如果鸡蛋碎了, 说明临界楼层一定在[1,p-1], f[i-1,p-1]
2.如果鸡蛋没碎, 说明临界楼层一定在[p+1,len], f[i,len-p]  --相当于第p层变第0层了
所以，最坏情况下，在第p层扔鸡蛋要尝试的次数 = max(f[i-1,p-1], f[i,len-p]) + 1
所以，最优子结构 f[i,len] = min{在第p层扔鸡蛋要尝试的次数}，要找这个p

边界条件:
len=0, f[i,0]=0  --总共0层楼，不用试
i=1, f[1,len]=len --只剩下一个鸡蛋了，就只能一层一层试，不能再把鸡蛋给弄碎了

目标: f[k,n]

*/


/*
递推
用区间动规做，示例通过，但有些case超时了
可能暴力遍历区间长度太暴力了。或许不是所有区间都要计算。如果可以用二分法找p的话
这样得用 dfs+记忆化搜索 了
*/

class Solution {
   public:
    int superEggDrop(int k, int n) {
        // 1e9 因为要算尝试次数的最小值
        vector<vector<int> > f(k + 1, vector<int>(n + 1, 1e9));

        // 边界
        for (int i = 0; i <= k; ++i)
            f[i][0] = 0;
        for (int len = 1; len <= n; ++len)
            f[1][len] = len;

        // for区间
        for (int len = 1; len <= n; ++len) {
            // for鸡蛋个数
            for (int i = 1; i <= k; ++i) {
                // 区间里面找一个p，使 f[i][len] 最小。p的范围，看下标。
                for (int p = 1; p <= len; ++p) {
                    int timesp = max(f[i - 1][p - 1], f[i][len - p]);
                    f[i][len] = min(f[i][len], timesp + 1);
                }
            }
        }
        return f[k][n];
    }
};


/*
dfs + 记忆化搜索
还没加二分查找的功能
一样的case上超时了。。
*/

class Solution {
   public:
    int superEggDrop(int k, int n) {
        f = vector<vector<int> >(k + 1, vector<int>(n + 1, 1e9));
        // dfs
        dfs(k, n);
        return f[k][n];
    }

   private:
    vector<vector<int> > f;
    // k个鸡蛋，n层楼
    void dfs(int k, int n) {
        // 边界
        if (k == 1) {
            f[k][n] = n;
            return;
        }
        if (n == 0) {
            f[k][n] = 0;
            return;
        }
        if (n == 1) {
            f[k][n] = 1;
            return;
        }
        // 记忆化
        if (f[k][n] != 1e9)
            return;

        // 本层逻辑
        for (int p = 1; p <= n; ++p) {
            dfs(k - 1, p - 1);
            dfs(k, n - p);
            int timesp = max(f[k - 1][p - 1], f[k][n - p]);
            f[k][n] = min(f[k][n], timesp + 1);
        }
    }
};

/*
dfs + 记忆化搜索 + 二分查找 找p

在第p层扔鸡蛋要尝试的次数 = max(f[i-1,p-1], f[i,len-p]) + 1
最优子结构: f[i,len] = min{在第p层扔鸡蛋要尝试的次数}

分析单调性。固定鸡蛋个数(i)和总楼层数(len)，看值关于p的变化
p越大：p-1要尝试的楼层越多，所以f[i-1,p-1]越大；len-p要尝试的楼层越少，所以f[i,len-p]越小
也就是说，f[i-1,p-1]是单调递增的，f[i,len-p]是单调递减的
子结构的代表是，两者的max要最小，所以要找的点p满足: f[i-1,p-1]=f[i,len-p]

所以可以用二分查找法找p
*/

class Solution {
   public:
    int superEggDrop(int k, int n) {
        f = vector<vector<int> >(k + 1, vector<int>(n + 1, 1e9));
        // dfs
        dfs(k, n);
        return f[k][n];
    }

   private:
    vector<vector<int> > f;
    // k个鸡蛋，n层楼
    void dfs(int k, int n) {
        // 边界
        if (k == 1) {
            f[k][n] = n;
            return;
        }
        if (n == 0) {
            f[k][n] = 0;
            return;
        }
        if (n == 1) {
            f[k][n] = 1;
            return;
        }
        // 记忆化
        if (f[k][n] != 1e9)
            return;

        // 本层逻辑 二分查找p
        int left = 1;
        int right = n;
        while (left <= right) {
            int p = (left + right) / 2;
            dfs(k - 1, p - 1);  // broken
            dfs(k, n - p);      // not broken
            if (f[k - 1][p - 1] > f[k][n - p]) {
                right = p - 1; // f[k - 1][p - 1] 关于p单调递增，要减小这个值，所以要在左半边继续找
                f[k][n] = min(f[k][n], f[k - 1][p - 1] + 1);
            } else {
                left = p + 1; // f[k][n - p] 关于p单调递减，要减小这个值，所以要在右半边继续找
                f[k][n] = min(f[k][n], f[k][n - p] + 1);
            }
        }
        return;
    }
};