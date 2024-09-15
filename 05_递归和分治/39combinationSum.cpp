#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

/*
39. 组合总和
https://leetcode.cn/problems/combination-sum/

*/

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->target = target;
        sum = 0;
        dfs();
        return ans;
    }

   private:
    vector<int> candidates;
    int target;
    int sum;
    vector<vector<int>> ans;
    vector<int> combine;
    unordered_set<string> h;

    void dfs() {
        // 边界条件
        if (sum > target)
            return;
        if (sum == target && h.find(hash(combine)) == h.end()) {
            ans.push_back(combine);
            h.insert(hash(combine));
            return;
        }
        // 本层逻辑
        for (int& candidate : candidates) {
            combine.push_back(candidate);
            sum += candidate;
            dfs();
            sum -= candidate;
            combine.pop_back();
        }
    }

    string hash(vector<int> v) {
        sort(v.begin(), v.end());
        string s;
        for (int& x : v)
            s += to_string(x);
        return s;
    }
};