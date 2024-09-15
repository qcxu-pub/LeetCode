#include <string>
#include <vector>
using namespace std;

/*
344. 反转字符串
https://leetcode-cn.com/problems/reverse-string/

双指针
*/

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        for (int i = 0; i < s.size(); ++i) {
            if (i < j) {
                swap(s, i, j);
                --j;
            } else {
                break;
            }
        }
    }

   private:
    void swap(vector<char>& s, int i, int j) {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
};