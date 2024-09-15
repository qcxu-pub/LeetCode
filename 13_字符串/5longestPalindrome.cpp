#include <string>
#include <vector>
using namespace std;

/*
5. 最长回文子串
https://leetcode-cn.com/problems/longest-palindromic-substring/

暴力: 枚举每个子串O(n^2)，判断是否回文O(n) -->O(n^3)
朴素: 枚举每个回文中心O(n)，向两侧拓展O(n) -->O(n^2)
哈希+二分: 枚举每个回文中心O(n)，二分查找可以拓展的长度O(logn) -->O(nlogn)

重点: 哈希+二分
*/


/*
朴素: 回文中心向两侧拓展
回文有个中心
如果回文长度为奇数，那中心是一个数
如果回文长度为偶数，那中心是一个空
--> 枚举中心点O(n)，两侧拓展O(n)，看最长能拓展多长 -->O(n^2)

*/

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ansStart = 0;
        int ansLen = 0;

        // 奇回文串
        for (int center = 0; center < n; ++center) {
            int l = center - 1;
            int r = center + 1; // 中心是center
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // [l+1,r-1]
            if (l + 1 >= 0 && r - 1 < n && r - l - 1 > ansLen) {
                ansLen = r - l - 1;
                ansStart = l + 1;
            }
        }

        // 偶回文串
        for (int center = 0; center < n; ++center) {
            int l = center - 1;
            int r = center;  // 中心是[center-1,center]中间的空格
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // [l+1,r-1]
            if (l + 1 >= 0 && r - 1 < n && r - l - 1 > ansLen) {
                ansLen = r - l - 1;
                ansStart = l + 1;
            }
        }
        return s.substr(ansStart, ansLen);
    }
};


/*
优化: 哈希+二分 O(nlogn)
朴素为什么慢？因为有逐字符比较。hash可以得到得到任意子串的hash值。这样这层复杂度可以从O(n)->O(1)
hash判断是否回文，具体的实现方法是: 正着读和倒着读是否一样 
O(1)得到子串hash，需要计算前缀字符串hash(正着读)和后缀字符串hash(倒着读)

二分答案，把求解问题变成判定问题 O(logn)
因为拓展时有一个分界点，扩展步数小于这个值的时候是ok的，大于这个值的时候就不ok了。所以可以用二分答案

这题我定义的前缀下标从1开始了。跟之前不太一样。不然后缀会出现+2，太绕了。。
缺点就是要把边界情况分开来写

*/

class Solution {
   public:
    string longestPalindrome(string s) {
        n = s.size();

        preH = vector<long long>(n, 0);
        sufH = vector<long long>(n, 0);
        powB = vector<long long>(n, 0);

        // 前缀 H[i]-H[i-1] = s[i]
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                preH[i] = (s[i] - 'a' + 1) % p;
                powB[i] = 1;
            } else {
                preH[i] = (preH[i - 1] * b + (s[i] - 'a' + 1)) % p;
                powB[i] = powB[i - 1] * b % p;
            }
        }
        // cout << "preH = " << calcHash(0,0) << "," << calcHash(1,1) << "," << calcHash(2,2) << "," << calcHash(3,3) << endl;

        // 后缀 H[i]-H[i+1]=s[i]
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1)
                sufH[i] = (s[i] - 'a' + 1) % p;
            else
                sufH[i] = (sufH[i + 1] * b + (s[i] - 'a' + 1)) % p;
        }
        // cout << "sufH = " << calcReverseHash(971,971) << "," << calcReverseHash(970,970) << "," << calcReverseHash(969,969) << "," << calcReverseHash(968,968) << endl;

        int ansStart = 0;
        int ansLen = 0;

        // 奇回文串  [center-len,center-1][center][center+1,center+len]
        for (int center = 0; center < n; ++center) {
            // 用二分法求解从center往两侧可以拓展多少字符
            // left和right是拓展长度len的上下界
            // left: 要让right可以取到0，有条件: left < right
            // right: center-len>=0, center+len<=n-1
            int left = -1, right = min(center, n - 1 - center);
            while (left < right) {
                int mid = (left + right + 1) / 2;  // +1，因为后面是left=mid
                // 如果当前字符串是回文，那说明可能还能再往外拓展，应该往大的那边继续找
                if (calcHash(center - mid, center + mid) == calcReverseHash(center - mid, center + mid))
                    left = mid;  // 当前长度也可能是答案
                else
                    right = mid - 1;
            }
            // right就是二分查找的答案，也就是拓展长度 len=right
            // [center-right, center+right]
            if (2 * right + 1 > ansLen) {
                ansLen = 2 * right + 1;
                ansStart = center - right;
            }
        }

        // 偶回文串
        // [center-len-1,center-2][center-1,center][center+1,center+len]
        for (int center = 1; center < n; ++center) {
            // right: center-len-1>=0, center+len<=n-1
            int left = -1, right = min(center - 1, n - 1 - center);
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (calcHash(center - mid - 1, center + mid) == calcReverseHash(center - mid - 1, center + mid))
                    left = mid;
                else
                    right = mid - 1;
            }

            // len = right, (center+len)-(center-len-1)+1 = 2 * len + 2
            if (2 * right + 2 > ansLen) {
                ansLen = 2 * right + 2;
                ansStart = center - right - 1;
            }
        }

        return s.substr(ansStart, ansLen);
    }

   private:
    int n;
    int b = 131;
    int p = 1e9 + 7;
    vector<long long> preH;
    vector<long long> sufH;
    vector<long long> powB;

    // 前缀 子串[l,r]的hash
    // hash("oba") = hash("fooba") - hash("fo000")
    // calcHash(2,4) = hash(4) - hash(1) * b^3
    long long calcHash(int l, int r) {
        if (l == 0)
            return (preH[r] % p + p) % p;
        else
            return ((preH[r] - preH[l - 1] * powB[r - l + 1]) % p + p) % p;
    }

    // 后缀 子串[l,r]的hash s="foobar"
    // hash("abo") = hash("rabo") - hash("r000")
    // calcReverseHash(2,4) = hash(2) - hash(5) * b^3
    long long calcReverseHash(int l, int r) {
        if (r == n - 1)
            return (sufH[l] % p + p) % p;
        else
            return ((sufH[l] - sufH[r + 1] * powB[r - l + 1]) % p + p) % p;
    }
};
