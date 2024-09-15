#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
811. 子域名访问计数
https://leetcode-cn.com/problems/subdomain-visit-count/

*/

class Solution {
   public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (string& domain : cpdomains) {
            int cnt = 0;
            for (int i = 0; i < domain.length(); ++i) {
                if (domain[i] == ' ') {
                    cnt = stoi(domain.substr(0, i));
                    string str = domain.substr(i + 1);
                    h[str] += cnt;
                } else if (domain[i] == '.') {
                    string str = domain.substr(i + 1);
                    h[str] += cnt;
                }
            }
        }
        vector<string> ans;
        for (auto& kv : h) {
            string k = kv.first;
            int v = kv.second;
            ans.push_back(to_string(v) + ' ' + k);
        }
        return ans;
    }

   private:
    unordered_map<string, int> h;
};