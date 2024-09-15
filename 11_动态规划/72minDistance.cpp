#include <string>
#include <vector>
using namespace std;

/*
72. 编辑距离
https://leetcode-cn.com/problems/edit-distance/

跟LCS很像。子问题就是word1的前i个，和word2的前j个
状态: f[i,j]表示，word1的前i个 变为 word2的前j个 的最小编辑距离。只关心最少变多少次，具体怎么变 的不关心

状态转移方程(从哪来):
    插入: f[i,j] = f[i-1,j] + 1 --在word1上增加一个字符word1[i]。如: text1="eb", text2="ebc"
    删除: f[i,j] = f[i,j-1] + 1 --在word1上删除一个字符，相当于在word2上增加一个字符word2[j]。如: text1="ebc", text2="eb"
    替换: f[i,j] = f[i-1,j-1] + eq, eq=1 if word1[i] != word2[j]
    三者取min
    如果这三个操作的权重不同，那加的就不是1了，而是权值

状态转移方程(到哪去):
    插入: f[i+1,j] = min(f[i+1,j], f[i,j]+1)
    删除: f[i,j+1] = min(f[i][j+1], f[i,j]+1)
    替换: f[i+1,j+1] = min(f[i+1,j+1], f[i][j]+eq), eq=1 if word1[i+1] != word2[j+1]

初值: f[i,0]=i, f[0,j]=j  --删空
目标: f[n,m]
时间复杂度: O(n*m)
*/

/*从哪里来*/
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // 0.下标变1
        word1 = " " + word1;
        word2 = " " + word2;

        // 1.状态定义，边界初始化
        vector<vector<int> > f(n + 1, vector<int>(m + 1, 1e9));  //因为要求最小值
        for (int i = 0; i <= n; ++i)
            f[i][0] = i;
        for (int j = 0; j <= m; ++j)
            f[0][j] = j;

        // 2.遍历所有状态，决策
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int t1 = f[i][j - 1] + 1;
                int t2 = f[i - 1][j] + 1;
                int t3 = f[i - 1][j - 1] + (word1[i] != word2[j]);
                f[i][j] = min(min(t1, t2), t3);
            }
        }

        // 3.目标
        return f[n][m];
    }
};


/*到哪里去*/

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // 0.下标变1
        word1 = " " + word1;
        word2 = " " + word2;

        // 1.状态定义
        vector<vector<int> > f(n + 2, vector<int>(m + 2, 1e9));

        // 2.遍历所有状态，决策
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                // 边界初始化。第一个是" "
                if (i == 0) {
                    f[i][j] = j;
                }
                if (j == 0) {
                    f[i][j] = i;
                }
                // 状态转移
                f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
                f[i][j + 1] = min(f[i][j + 1], f[i][j] + 1);
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + (word1[i + 1] != word2[j + 1]));
            }
        }

        // for (int i = 0; i < n; ++i)
        //     for (int j = 0;  j < m; ++j)
        //         cout << "f[i,j]=f[" << i << "," << j << "]=" << f[i][j] << endl;

        return f[n][m];
    }
};