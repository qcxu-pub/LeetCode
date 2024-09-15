#include <string>
#include <vector>
using namespace std;

/*
螺丝和螺帽问题 · Nuts & Bolts Problem
https://www.jiuzhang.com/solutions/nuts-bolts-problem/

快速排序的应用
思路:
用同一个pivot，对 nuts 和 bolts 同时进行快排

*/

class Comparator {
   public:
    int cmp(string a, string b) {
        if (a.length() != b.length())
            return 2;

        a = toLow(a);
        b = toLow(b);
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i])
                continue;
            else if (a[i] > b[i])
                return 1;
            else if (a[i] < b[i])
                return -1;
        }
        return 0;
    }

    string toLow(string s) {
        string ans = "";
        for (char& ch : s) {
            if (ch >= 'A' && ch <= 'Z')
                ans.push_back(ch - 'A' + 'a');
            else
                ans.push_back(ch);
        }
        return ans;
    }
};

class Solution {
   public:
    void sortNutsAndBolts(vector<string>& nuts, vector<string>& bolts, Comparator compare) {
        int n = nuts.size();
        int m = bolts.size();
        if (m != n)
            return;
        quickSort(nuts, bolts, compare, 0, n - 1);
    }

   private:
    // 先找中轴元素pivot，将小元素放到pivot左边，大元素放到右边。然后分别对左边和右边的子数组进行快排
    void quickSort(vector<string>& nuts, vector<string>& bolts, Comparator compare, int start, int end) {
        if (start >= end)
            return;
        // 以 bolts[start] 为中轴，对 nuts 进行快排
        // index 说明了，比 bolts[start] 元素小的元素个数
        // nuts[start,index-1] 是比 pivot 小的，nuts[index+1,end] 是比 pivot 大的
        int index = partition(nuts, bolts[start], compare, start, end);
        partition(bolts, nuts[index], compare, start, end);

        // quickSort
        quickSort(nuts, bolts, compare, start, index - 1);
        quickSort(nuts, bolts, compare, index + 1, end);
    }

    int partition(vector<string>& v,
                  string pivot,
                  Comparator compare,
                  int start,
                  int end) {
        int m = start;
        for (int i = start + 1; i <= end; ++i) {
            // v[i] < pivot, v[i]就交换到左边，++m
            if (compare.cmp(pivot, v[i]) == 1 || compare.cmp(v[i], pivot) == -1) {
                swap(v, m, i);
                ++m;
            }
            // v[i] == pivot,
            // v[i]就交换到最左边保护起来。原来开始的位置元素要纳入排序
            else if (compare.cmp(pivot, v[i]) == 0 || compare.cmp(v[i], pivot) == 0) {
                swap(v, start, i);
                --i;
            }
            // v[i] > pivot, 就应该再pivot_index=m的右边，所以继续遍历就好了
            else
                continue;
        }
        // 把保护起来的结点交换到中轴的位置上
        swap(v, start, m);
        return m;
    }

    void swap(vector<string>& v, int i, int j) {
        string temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
};