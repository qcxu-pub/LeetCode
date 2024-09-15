#include <cstdio>
#include <iostream>
using namespace std;


#include "697findShortestSubArray.cpp"
int main() {
    Solution solu;
    vector<int> nums = {1,2,2,3,1};
    cout << "ans = " << solu.findShortestSubArray(nums) << endl;
}

/*
#include "15threeSum.cpp"
int main() {
    Solution solu;
    // vector<int> nums = {0,0,0};
    vector<int> nums = {-2,0,0,2,2};
    vector<vector<int> > ans = solu.threeSum(nums);
    for (vector<int>& vec: ans) {
        for (int& v: vec)
            cout << v << ",";
        cout << endl;
    }
}
*/

/*
#include "811subdomainVisits.cpp"
int main() {
    Solution solu;
    vector<string> cpdomains = {"9001 discuss.leetcode.com"};
    vector<string> ans = solu.subdomainVisits(cpdomains);
    for (string& a: ans)
        cout << a << ",";
}
*/

/*
#include "30findSubstring.cpp"
int main() {
    Solution solu;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    vector<int> ans = solu.findSubstring(s, words);
    for (int& a: ans)
        cout << a << ",";
}
*/

/*
#include "146LRUCache.cpp"
int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);  // 缓存是 {1=1}
    lRUCache->put(2, 2);  // 缓存是 {1=1, 2=2}
    cout << "1.get(1)=" << lRUCache->get(1) << endl;     // 返回 1
    lRUCache->put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << "2.get(2)=" << lRUCache->get(2) << endl;  // 返回 -1 (未找到)
    lRUCache->put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << "3.get(1)=" << lRUCache->get(1) << endl;  // 返回 -1 (未找到)
    cout << "4.get(3)=" << lRUCache->get(3) << endl;  // 返回 3
    cout << "5.get(4)=" << lRUCache->get(4) << endl;  // 返回 4
    return 0;
}
*/