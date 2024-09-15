# 1.字符串基础知识

```
#include <string>
// 定义
string x = "abc";
// 遍历1
for (int i = 0; i < s.length(); ++i)
    cout << s[i];
// 遍历2
for (char ch : s)
    cout << ch;
// 比较字符串是否相等
if (x == y)
    cout << "equal";

```

- [8. 字符串转换整数 (atoi) (median)](https://leetcode-cn.com/problems/string-to-integer-atoi/) |  [solution](https://leetcode-cn.com/problems/perfect-squares/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/8myAtoi.cpp)

- [709. 转换成小写字母 (easy)](https://leetcode-cn.com/problems/to-lower-case/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/709toLowerCase.cpp)

- [58. 最后一个单词的长度 (easy)](https://leetcode-cn.com/problems/length-of-last-word/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/58lengthOfLastWord.cpp)

- [771. 宝石与石头 (easy)](https://leetcode-cn.com/problems/jewels-and-stones/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/771numJewelsInStones.cpp)

- [387. 字符串中的第一个唯一字符 (easy)](https://leetcode-cn.com/problems/first-unique-character-in-a-string/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/387firstUniqChar.cpp)

- [14. 最长公共前缀 (easy)](https://leetcode-cn.com/problems/longest-common-prefix/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/14longestCommonPrefix.cpp)

- [344. 反转字符串 (easy)](https://leetcode-cn.com/problems/reverse-string/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/344reverseString.cpp)

- [541. 反转字符串 II (easy)](https://leetcode-cn.com/problems/reverse-string-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/541reverseStr.cpp)

- [151. 翻转字符串里的单词 (median)](https://leetcode-cn.com/problems/reverse-words-in-a-string/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/151reverseWords.cpp)

- [557. 反转字符串中的单词 III (easy)](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/557reverseWords.cpp)

- [917. 仅仅反转字母 (easy)](https://leetcode-cn.com/problems/reverse-only-letters/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/917reverseOnlyLetters.cpp)

- [415. 字符串相加 (easy)](https://leetcode-cn.com/problems/add-strings/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/415addStrings.cpp)


# 2.Rabin-Karp字符串哈希算法

```
Rabin-Karp是一种基于Hash的高效字符串搜索算法

要解决的问题: 可以代替后面的KMP算法解决模式匹配问题
已知: 长度为n的字符串s(文本串)，长度为m的字符串t(模式串)
问: t是否在s中出现过 (t是否为s的子串)

要解决上面的问题
朴素解法: 整一个长度为m的滑动窗口，依次比较子串是否相等。时间复杂度: 滑动窗口O(n)，比较子串O(m)，所以总体O(n*m)
Rabin-Karp算法: 时间复杂度O(m+n)

Rabin-Karp算法总体思想
如果是数值的话，通过除法和取模算出其中的一段，比较的时间复杂度O(1)。所以把字符串看成27进制数，也做这样的数值运算
所以计算s的每个长度为m的子串的hash值，检查是否与t的hash值相等
时间复杂度: 滑动窗口O(n)，字符串过hash转数值O(m)，整数比较O(1)。所以整体O(n+m)

选用的hash函数: 把字符串看作是b进制数，计算它在十进制下对p取模的值
通常的取值: b=131, p为大质数(1e9+7)。这样hash冲突的概率极小

那如何快速计算一个子串的hash值? 用前缀和!
举个例子: s = "foobar"
Hash("oba") = Hash("fooba") - Hash("fo000") = H[5] - H[2] * b^3
前缀和(下标从1开始) H[i] = Hash(s[0...i-1]) = (Hash[i-1] * b + s[i-1]) mod p
子串 Hash(s[l...r]) = (H[r+1] - H[l] * b^(r-l+1)) mod p  --> 时间复杂度O(1)

总结一下，三个思想:
1.把字符串看做数值，进制数
2.空间时间平衡，通过前缀的思路快速得到子串的hash值
3.取一段是通过四则运算得到的


使用Rabin-Karp算法解决字符串匹配问题的思路:
1.计算长度为m的模式串t的hash值，O(m)
2.计算长度为n的文本串s中，长度为m的子串的hash值。窗口滑到底，需要计算n-m+1次
3.比较每个子串和模式串的hash值，如果hash值不同，必然不匹配
4.Rabin-Karp在hash选取较好的时候，发生hash冲突的概率很小，就不需要用朴素的方法再次判断了
所以，总体时间复杂度 O(n+m)


该算法具有广泛适用性 --万金油算法
O(n)预处理+O(1)求出任意子串哈希值
可以配合二分查找、二分答案等技巧
可以作为字符串匹配、回文等一系列问题的次优解 --比最优解多一个log时间复杂度

```

- [28. 实现 strStr() (easy)](https://leetcode-cn.com/problems/implement-strstr/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/28strStr.cpp)


# 3.回文串/同构/子串系列问题

```
680/5/438

```

- [125. 验证回文串 (easy)](https://leetcode-cn.com/problems/valid-palindrome/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/125isPalindrome.cpp)

- [680. 验证回文字符串 Ⅱ (easy)](https://leetcode-cn.com/problems/valid-palindrome-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/680validPalindrome.cpp)

- [5. 最长回文子串 (median)](https://leetcode-cn.com/problems/longest-palindromic-substring/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/5longestPalindrome.cpp)

- [205. 同构字符串 (easy)](https://leetcode-cn.com/problems/isomorphic-strings/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/205isIsomorphic.cpp)

- [242. 有效的字母异位词 (easy)](https://leetcode-cn.com/problems/valid-anagram/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/242isAnagram.cpp)

- [49. 字母异位词分组 (median)](https://leetcode-cn.com/problems/group-anagrams/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/49groupAnagrams.cpp)

- [438. 找到字符串中所有字母异位词 (median)](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/438findAnagrams.cpp)


# 4.字符串+动态规划

```
跟LCS是一类问题
状态f[i,j]表示s的前i个字符，和t的前j个字符匹配
决策就考虑末尾字符i和j怎么用

```

- [10. 正则表达式匹配 (hard)](https://leetcode-cn.com/problems/regular-expression-matching/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/10isMatch.cpp)

- [115. 不同的子序列 (hard)](https://leetcode-cn.com/problems/distinct-subsequences/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/115numDistinct.cpp)

- [44. 通配符匹配 (hard)](https://leetcode-cn.com/problems/wildcard-matching/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/44isMatch.cpp)




# 5.KMP字符串模式匹配算法

```
字符串匹配问题
文本串s，模式串t。找出t在s中所有出现的位置
比如: t是否是s的子串? t在s中第一次出现的位置? 

字符串匹配问题常用解法
1.朴素。时间复杂度 O(n*m)
2.Rabin-Karp字符串哈希算法。时间复杂度 O(n+m)
3.KMP算法。时间复杂度 O(n+m)

朴素算法为什么慢?
举个例子: s="aaaaaaabaaac", t="aaaac"。t的前缀"aaaa"，s也有一堆"aaaaa..."，这种字符都一样的，滑动窗口滑过去，错一位还是一样的。时间耗在这里了
为了优化这个问题，可以先挖掘t的性质，然后把这个性质作为辅助，跟s进行匹配，从而加速比较。所以就分解成两个问题：
1.s跟t怎么配
2.t自己怎么配

t怎么量化地描述出来? 用了类似动规的算法
状态next[i]表示，t中以i结尾的非前缀子串，与t的前缀，能够匹配的最长长度 --这个衡量的就是错位的能力
举个例子: t="abababaac"
next[1]=0 NULL                                                        --没有这样的子串
next[2]=0 "b"                                                         --没有能跟t的前缀匹配的
next[3]=1 "ba","a"                                                    --"a"能跟t的前缀匹配，且最长=1
next[4]=2 "bab","ab","b"                                              --"ab"能跟t的前缀匹配，且最长=2
next[5]=3 "baba","aba","ba","a"                                       --"aba"能跟t的前缀匹配，且最长=3
next[6]=4 "babab","abab","bab","ab","b"                               --"abab"能跟t的前缀匹配，且最长=4
next[7]=5 "bababa","ababa","baba","aba","ba","a"                      --"ababa"能跟t的前缀匹配，且最长=5
next[8]=1 "bababaa","ababaa","babaa","abaa","baa","aa","a"            --"a"能跟t的前缀匹配，且最长=1
next[9]=0 "bababaac","ababaac","babaac","abaac","baac","aac","ac","c" --没有能跟t的前缀匹配的

再举个例子: t="aaaac"
next[1]=0 NULL
next[2]=1 "a"                     --跟t="aaaac"的前缀最长匹配"a"
next[3]=2 "aa","a"                --跟t="aaaac"的前缀最长匹配"aa"
next[4]=3 "aaa","aa","a"          --跟t="aaaac"的前缀最长匹配"aaa"
next[5]=0 "aaac","aac","ac","c"   --没有能跟t="aaaac"的前缀匹配的

再举个例子: t="abcbcabd"
next[1]=0 NULL
next[2]=0 "b"
next[3]=0 "bc","c"
next[4]=0 "bcb","cb","b"
next[5]=0 "bcbc","cbc","bc","c"
next[6]=1 "bcbca","cbca","bca","ca","a"                    --"a"
next[7]=2 "bcbcab","cbcab","bcab","cab","ab","b"           --"ab"
next[8]=0 "bcbcabd","cbcabd","bcabd","cabd","abd","bd","d"


这个next数组怎么用？快速的滑动窗口，可以快速定位下一步要去哪儿。因为这里维护了前缀重复的信息，循环元  --给我一种加速度的感觉。。
next[k]=v 往前跳，窗口就在往后移。因为上面next[i]取的是max，所以滑动的步数不会漏
还是第一个例子: t="abababaac"
   123456 7 89
t= ababab a ac        next[7]=5
     1234 5 6789
     abab a baac      next[5]=3
       12 3 456789
       ab a babaac    next[3]=1
          1 23456789
          a bababaac  next[1]=0
            123456789
            abababaac

所以，
状态: f[i]表示，以s[i]结尾的字符串与t的重叠最长长度
状态转移:
1.当s[i+1]=t[j+1]，说明现在遍历的是这里
      i
  aba b abaac
    a b ababaac
      j
  所以 i 和 j 同时往后移，多匹配一个字符就好. f[i]=j，++i,++j
2.当s[i+1]!=t[j+1]，说明现在遍历到这里了
         i=7
  ababab a ac
    abab a baac
         j=5         --> s[i+1]='a'!=t[j+1]='b' --> next[5]=3
      ab a babaac
         j=3         --> s[i+1]='a'!=t[j+1]='b' --> next[3]=1
         a bababaac
         j=1         --> s[i+1]='a'!=t[j+1]='b' --> next[1]=0
           abababaac
         j=0         --> s[i+1]='a'==t[j+1]='a' --> ++i,++j
所以滑动一下，下一个比较的是 s[i+1] 和 t[next[j]+1] 其他的都可以跳过

```

- [28. 实现 strStr() (easy)](https://leetcode-cn.com/problems/implement-strstr/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/28strStr.cpp)

- [686. 重复叠加字符串匹配 (median)-TODO](https://leetcode-cn.com/problems/repeated-string-match/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/13_字符串/686repeatedStringMatch.cpp)
