#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

/*

思路：
要求的是变化步数最少。这种适合BFS，因为BFS可以求层数，层越浅，变化就越少
序列本身是点，怎么改是边（分支）：依次替换每个字符，替代的字符有限，且替换完了还要在基因库里，且之前没有被遍历过（之前遍历的一定层数更小）
*/

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        // vector --> hash，方便后续查找
        for (string& b : bank) {
            hashBank.insert(b);
        }
        if (hashBank.find(end) == hashBank.end())
            return -1;

        const char gene[4] = {'A', 'C', 'G', 'T'};
        q.push(start);
        depth[start] = 0;
        while (!q.empty()) {
            // 1.取队头
            string s = q.front();
            q.pop();
            // 2.扩展队头
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 4; ++j) {
                    string ns = s;
                    ns[i] = gene[j];
                    if (hashBank.find(ns) == hashBank.end())
                        continue;
                    if (depth.find(ns) != depth.end())
                        continue;
                    depth[ns] = depth[s] + 1;
                    q.push(ns);

                    if (ns == end)
                        return depth[ns];
                }
            }
        }
        return -1;
    }

   private:
    unordered_set<string> hashBank;
    unordered_map<string, int> depth;
    queue<string> q;
};