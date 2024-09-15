#include <string>
using namespace std;

/*
541. 反转字符串 II
https://leetcode-cn.com/problems/reverse-string-ii/

k=2: 0/1反转,2/3保持,4/5反转
if i%(2*k)==0: [i, i+k-1] 反转
if i%(2*k)==k: [i, i+k-1] 保持
*/

class Solution {
   public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); ++i) {
            if (i % (2 * k) == 0) {
                int e1 = s.length() - 1;
                int e2 = i + k - 1;
                reverse(s, i, min(e1, e2));
            }
        }
        return s;
    }

   private:
    void swap(string& s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    void reverse(string& s, int start, int end) {
        for (; start <= end; ++start, --end) {
            swap(s, start, end);
        }
    }
};