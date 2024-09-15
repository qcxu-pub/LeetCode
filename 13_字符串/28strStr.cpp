#include <string>
#include <vector>
using namespace std;

/*
28. 实现 strStr()
https://leetcode-cn.com/problems/implement-strstr/

*/


/*Rabin-Karp字符串哈希算法*/

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int b = 131, p = 1e9 + 7;
        int n = haystack.size();
        int m = needle.size();

        // haystack 前缀和，下标从1开始
        vector<long long> H(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // H[i]下标从1开始，haystack下标从0开始
            // ch='a'->1, ch='b'->2。'a'不能是0，因为aab和ab是不一样的
            H[i] = (H[i - 1] * b + (haystack[i - 1] - 'a' + 1)) % p;
        }

        // needle hash
        long long Hneedle = 0;
        long long powBM = 1;  // b^m
        for (char ch : needle) {
            Hneedle = (Hneedle * b + (ch - 'a' + 1)) % p;
            powBM = powBM * b % p;
        }

        // match s[l~r]。下标跟前缀和的一致。len = r-l+1 = m
        for (int l = 1; l <= n - m + 1; ++l) {
            int r = l + m - 1;
            // haystack子串hash。担心算出来的是负数，所以有了 (...+p)%p 这种操作
            if (((H[r] - H[l - 1] * powBM) % p + p) % p == Hneedle)
                return l - 1;  // H[l] --> s[l-1]
        }
        return -1;
    }
};


/*
KMP字符串模式匹配算法: 完成了快速错位。下面是t的自匹配过程
            12345678         -- i
        t = abababaac        -- next[1]=0
i=2,j=0      abababaac       -- 不满足j>0, t[i]=='b' != t[j+1]=='a' --> next[2]=0, ++i
i=3,j=0       abababaac      -- 不满足j>0, t[i]==t[j+1]=='a' --> ++j, next[3]=1, ++i
i=4,j=1       abababaac      -- t[i]==t[j+1]=='b' --> ++j, next[4]=2, ++i
i=5,j=2       abababaac      -- t[i]==t[j+1]=='a' --> ++j, next[5]=3, ++i
i=6,j=3       abababaac      -- t[i]==t[j+1]=='b' --> ++j, next[6]=4, ++i
i=7,j=4       abababaac      -- t[i]==t[j+1]=='a' --> ++j, next[7]=5, ++i
i=8,j=5       abababaac      -- j>0 && t[i]=='a' != t[j+1]=='b' --> j=next[5]=3
i=8,j=3          abababaac   -- j>0 && t[i]=='a' != t[j+1]=='b' --> j=next[3]=1
i=8,j=1            abababaac -- t[i]=='c' != t[2]=='b' --> j=next[1]=0 --> next[8]=0

*/

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int n = haystack.length();
        int m = needle.length();

        // 下标从1开始
        haystack = " " + haystack;
        needle = " " + needle;

        // needle 的 next[i]。needle 的自匹配
        vector<int> next(m + 1, 0);  // 下标从1开始
        next[1] = 0;  // needle字符串下标也是1开始，0个它的前一个
        for (int i = 2, j = 0; i <= m; ++i) {
            // 找下一个相同的头的位置j, i>j
            // j > next[j]，index往前跳，窗口往后滑
            // next[j] 之前有赋值过 next[i]=j，所以一步滑到位
            while (j >= 1 && needle[i] != needle[j + 1])
                j = next[j];
            if (needle[i] == needle[j + 1])
                ++j;  // 外循环有++i
            next[i] = j;
            // cout << "needle - next[" << i << "]=" << next[i] << endl;
        }
        // haystack 和 needle 的匹配。haystack[i] --> f[i]
        vector<int> f(n + 1, 0);
        for (int i = 1, j = 0; i <= n; ++i) {
            while (j >= 1 && (j == m || haystack[i] != needle[j + 1]))
                j = next[j];
            if (haystack[i] == needle[j + 1])
                ++j;  // 外循环有++i
            f[i] = j;
            // cout << "match - f[" << i << "]=" << f[i] << endl;
        }

        // f[i]=m，说明以s[i]结尾的字符串完全匹配了t字符串
        // 题目要求的就是第一个完全匹配的地方
        for (int i = 1; i <= n; ++i) {
            if (f[i] == m) {
                return (i - m + 1) - 1;  //下标从1开始变成下标从0开始
            }
        }
        return -1;
    }
};
