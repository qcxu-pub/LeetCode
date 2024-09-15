#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
17. 电话号码的字母组合
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

思路：
23-->[ad,ae,af, bd,be,bf, cd,ce,cf]
状态由两个组成：选了数字x，数字x对应的不同字母y组成的字符串
*/

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        alphabets['2'] = "abc";
        alphabets['3'] = "def";
        alphabets['4'] = "ghi";
        alphabets['5'] = "jkl";
        alphabets['6'] = "mno";
        alphabets['7'] = "pqrs";
        alphabets['8'] = "tuv";
        alphabets['9'] = "wxyz";

        dfs(0, "");

        if (digits == "")
            return {};
        else
            return ans;
    }

   private:
    string digits;
    unordered_map<char, string> alphabets;
    vector<string> ans;

    // 参数对应了两个状态变量
    void dfs(int index, string str) {
        // 边界条件
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        // 本层要干的事情
        int number = digits[index];
        for (char ch : alphabets[number]) {
            // str += ch; //不能写在这里。23 --> ad,ade,...。如果写这里下面就还原现场，虽然这不是个全局变量
            dfs(index + 1, str + ch);
        }
    }
};


/* 上述代码的一个可优化点：参数传string比较耗性能，可以把这个变成全局变量，但要注意还原现场 */

class Solution2 {
   public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        alphabets['2'] = "abc";
        alphabets['3'] = "def";
        alphabets['4'] = "ghi";
        alphabets['5'] = "jkl";
        alphabets['6'] = "mno";
        alphabets['7'] = "pqrs";
        alphabets['8'] = "tuv";
        alphabets['9'] = "wxyz";

        dfs(0);

        if (digits == "")
            return {};
        else
            return ans;
    }

   private:
    string digits;
    unordered_map<char, string> alphabets;
    vector<string> ans;
    string str;  // 另一个状态变量在这里

    // 参数对应的1个状态变量
    void dfs(int index) {
        // 边界条件
        if (index == digits.length()) {
            ans.push_back(str);
            return;
        }
        // 本层要干的事情
        int number = digits[index];
        for (char ch : alphabets[number]) {
            str.push_back(ch);
            dfs(index + 1);
            str.pop_back();
        }
    }
};
