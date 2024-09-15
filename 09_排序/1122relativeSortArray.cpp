#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
1122. 数组的相对排序
https://leetcode-cn.com/problems/relative-sort-array/

*/

/*
基于比较排序
利用哈希表对arr2建立数值到索引的映射
自定义排序方式
*/
class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> arr2orders;
        for (int i = 0; i < arr2.size(); ++i) {
            arr2orders[arr2[i]] = i;
        }
        // lambda表达式 O(nlogn)
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            int xPos = arr2orders.find(x) != arr2orders.end() ? arr2orders[x] : arr2.size();
            int yPos = arr2orders.find(y) != arr2orders.end() ? arr2orders[y] : arr2.size();
            return xPos < yPos || (xPos == yPos && x < y);
        });
        return arr1;
    }
};


/*
基于非比较排序
计数排序，按arr2的顺序访问计数数组
*/
class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);  // 看题意，arr1元素值域最大1000
        for (int& val : arr1) {
            count[val]++;
        }

        vector<int> ans;
        // 按arr2的顺序遍历 O(N)
        for (int& val : arr2) {
            while (count[val] > 0) {
                ans.push_back(val);
                count[val]--;
            }
        }
        // 没有在arr2里面的元素 O(M)
        for (int val = 0; val <= 1000; ++val) {
            while (count[val] > 0) {
                ans.push_back(val);
                count[val]--;
            }
        }
        return ans;
    }
};
