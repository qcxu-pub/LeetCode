#include <string>
#include <vector>
using namespace std;

#include <cstdio>
#include <iostream>

/*
1143. 最长公共子序列
https://leetcode-cn.com/problems/longest-common-subsequence/

text1="abcde", text2="ace"
        a      ac       ace
a      1(a)    1(a)     1(a)
ab     1(a)    1(a)     1(a)
abc    1(a)    2(ac)    2(ac)
abcd   1(a)    2(ac)    2(ac)
abcde  1(a)    2(ac)    3(ace)

如果末尾不一样的话，len(i,j) = max(len(i-1,j), len(i,j-1))
如果末尾一样的话，len(i,j) = len(i-1,j-1) + 1

确定“状态”的原则：找变化信息。这里是子串的边界
确定“最优子结构”的原则：寻找代表。只关心长度，不关系内容。比如：abcd..., acbd...，这之前的最长公共子序列是abd或者acd，但无所谓是哪个
确定“阶段”的原则：线性增长的轮廓。这里就是一行一行从左往右遍历，两重for循环
确定“决策”的原则：人工模拟的时候是怎么个递推的
*/

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        // trick: 边界条件很麻烦，所以下标从1开始遍历
        text1 = " " + text1;
        text2 = " " + text2;

        int m = text1.length();
        int n = text2.length();
        vector<vector<int> > ans(m, vector<int>(n, 0));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                } else {
                    ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
                }
            }
        }
        return ans[m - 1][n - 1];
    }
};


/*
拓展: 打印方案。这里是二维的
要记录是从哪里转移过来的
*/

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        text1 = " " + text1;
        text2 = " " + text2;
        int m = text1.size();
        int n = text2.size();
        vector<vector<int> > ans(m, vector<int>(n, 0));
        preType = vector<vector<int> >(m, vector<int>(n, -1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                    preType[i][j] = 2;
                } else {
                    if (ans[i - 1][j] > ans[i][j - 1]) {
                        ans[i][j] = ans[i - 1][j];
                        preType[i][j] = 0;
                    } else {
                        ans[i][j] = ans[i][j - 1];
                        preType[i][j] = 1;
                    }
                }
            }
        }

        // 打印方案
        this->text1 = text1;
        this->text2 = text2;
        print(m - 1, n - 1);

        return ans[m - 1][n - 1];
    }

   private:
    string text1;
    string text2;
    vector<vector<int> > preType;

    void print(int i, int j) {
        // 递归边界，是人为加的" "
        if (i == 0 || j == 0)
            return;
        // 递归
        if (preType[i][j] == 0)
            print(i - 1, j);
        else if (preType[i][j] == 1)
            print(i, j - 1);
        else {
            print(i - 1, j - 1);
            cout << text1[i] << ",";
        }
    }
};