#include <vector>
#include <algorithm>
using namespace std;

/*
455. 分发饼干
https://leetcode-cn.com/problems/assign-cookies/

g[i1]<=g[i2]<=s[j]，这样满足i2这个孩子更好
证明：
如果此时满足g[i2]，则答案+1，剩下g[i1]还没有被满足 --(1)
如果此时满足g[i1]，则答案+1，剩下g[i2]还没有被满足 --(2)
但g[i1]更小，更容易被满足。所以能满足g[i2]的，一定能满足g[i1]。所以(1)满足决策包容性，方案更优

所以，
1.一块饼干(尺寸s[j])发给谁？给满足g[i]<=s[j]的最大的g[i] --找前驱
2.一个孩子(胃口g[j])吃哪块饼干？吃满足s[j]>=g[i]的最小s[j] --找后继
所以把饼干和孩子都排序，这样依次匹配就好，不用二分了
*/

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int j = 0;
        for (int child : g) {
            // 饼干太小了，一个孩子都满足不了
            while (j < s.size() && child > s[j]) {
                j++;
            }
            // 如果停在合法范围，把这块饼干用掉
            if (j < s.size()) {
                ans++;
                j++;
            }
        }
        return ans;
    }
};