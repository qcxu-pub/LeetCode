#include <vector>
using namespace std;

/*
130. 被围绕的区域
https://leetcode-cn.com/problems/surrounded-regions/

之前用bfs做过。这里用并查集做。
无向图，无序二元关系，并查集可以解决无序二元关系的问题
方向数组
*/

class Solution {
   public:
    void solve(vector<vector<char> >& board) {
        m = board.size();
        n = board[0].size();

        makeSet();  // fa初始化

        // tricky: 定义一个一个外界无限大区域的点
        // board里面的点是第0~m*n-1个，那外界无限大区域是第m*n个
        int outside = num(m - 1, n);  //= m*n

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X')
                    continue;
                
                // board[i][j] == 'O'

                // 可优化: 其实只要往右往下连个方向就好了，因为往左的边和往右的边是一样的
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    // cout << i << "," << j << "..." << ni << "," << nj << endl;

                    // (ni,nj)出界，说明(i,j)是边界，跟外界相连，而且是'O'
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                        unionSet(num(i, j), outside);
                    // (ni,nj)没出界，但(i,j)(ni,nj)都是'O'，那建立连通关系
                    else if (board[ni][nj] == 'O')
                        unionSet(num(i, j), num(ni, nj));
                }
            }
        }

        // ans
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // outside 也要find一下的
                if (board[i][j] == 'O' && find(num(i, j)) != find(outside))
                    board[i][j] = 'X';
            }
        }
    }

   private:
    int n, m;
    vector<int> fa;
    // 方向数组
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};

    // 把二维数组转一维的
    int num(int i, int j) {
        return i * n + j;
    }

    // DisjointSet
    void makeSet() {
        //多出来的1个放无限大区域点
        fa = vector<int>(m * n + 1, 0);
        for (int x = 0; x <= m * n; ++x)
            fa[x] = x;
    }

    // DisjointSet
    int find(int x) {
        // 边界: 根节点
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    // DisjointSet
    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            fa[x] = y;
    }
};