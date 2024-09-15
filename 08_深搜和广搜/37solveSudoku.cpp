#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
37. 解数独
https://leetcode.cn/problems/sudoku-solver/

36题是否有解，作为剪枝条件
填一个格子就验证一下。及时减掉不合法的分支
搜索树：确定好一个格子数值，尝试下一个格子不同的数值，就是不同的分支

蛮力搜索，就找第一个空位置枚举填充。不是枚举每个空位置。因为位置是无序的，先填哪个后填哪个，无所谓的

*/

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

   private:
    // 返回是否合法
    bool dfs(vector<vector<char>>& board) {
        // 递归边界，不合法直接退出
        if (!isValidSudoku(board))
            return false;
        // 递归边界，全部填完了，正常退出
        // 找第一个空位置
        pair<int, int> pos = findFirstEmpty(board);
        int x = pos.first;
        int y = pos.second;
        if (x == -1)
            return true;

        // 本层逻辑: 填一个数，然后到下一层
        for (char digit = '1'; digit <= '9'; ++digit) {
            board[x][y] = digit;
            bool res = dfs(board);
            // 填完了，没空格了，不要还原现场了，直接返回
            if (res)
                return true;
            else
                board[x][y] = '.';  //还原现场
        }
        // 分支都遍历完了还不行
        return false;
    }

    pair<int, int> findFirstEmpty(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char digit = board[i][j];
                if (digit == '.')
                    return {i, j};
            }
        }
        return {-1, -1};
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> used_block[9];
        unordered_set<char> used_row[9];
        unordered_set<char> used_col[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;

                int idx = hash(int(i / 3), int(j / 3));
                auto ans_row = used_row[i].find(ch);
                auto ans_col = used_col[j].find(ch);
                auto ans_block = used_block[idx].find(ch);

                if (ans_row != used_row[i].end() ||
                    ans_col != used_col[i].end() ||
                    ans_block != used_block[idx].end())
                    return false;

                used_row[i].insert(ch);
                used_col[j].insert(ch);
                used_block[idx].insert(ch);
            }
        }
        return true;
    }

    // 二维转一维
    int hash(int x, int y) {
        return 3 * x + y;
    }
};


/*
上面的超时了

更深层次的剪枝:

1.先找容易填的，就是先填候选池少的
所以不是找第一个可以填充的格子，而是找候选数值最少的格子
findFirstEmpty -> findMinimumProbability

2.枚举1-9了，再判断行不行
就枚举这个格子可能的取值，减少分支
isValidSudoku -> getAvailableDigits

具体的做法是：
每行、每列、每个九宫格，分别维护一个9位bool数组，保存还可以填哪些数字
当所在的格子行、列、九宫格，某个值都还能填的时候，说明该格子可以填这个数

*/

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        // 初始化row,col,box
        for (int i = 0; i < 9; ++i) {
            for (int digit = 1; digit <= 9; ++digit) {
                row[i][digit] = true;
                col[i][digit] = true;
                box[i][digit] = true;
            }
        }

        // 统计每行/每列/每个大格子还可以填的值
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int digit = board[i][j] - '0';
                row[i][digit] = false;
                col[j][digit] = false;
                box[hash(i / 3, j / 3)][digit] = false;
            }
        }

        //
        dfs(board);
    }

   private:
    bool row[9][10];  // 9行，每一行一个bool vector
    bool col[9][10];
    bool box[9][10];

    // 二维转一维
    int hash(int x, int y) {
        return 3 * x + y;
    }

    bool dfs(vector<vector<char>>& board) {
        // 递归边界，全部都填满了
        pair<int, int> pos = findMinimumProbability(board);
        int x = pos.first;
        int y = pos.second;
        if (x == -1)
            return true;

        // 本层逻辑。上面找到了要填充的位置，从候选值最少的格子开始填。然后这里考虑要填充的值
        vector<int> availableDigits = getAvailableDigits(x, y);
        for (int digit : availableDigits) {
            board[x][y] = digit + '0';
            row[x][digit] = false;
            col[y][digit] = false;
            box[hash(x / 3, y / 3)][digit] = false;
            // 递归
            bool isFinish = dfs(board);
            if (isFinish)
                return true;
            // 还原现场
            box[hash(x / 3, y / 3)][digit] = true;
            col[y][digit] = true;
            row[x][digit] = true;
            board[x][y] = '.';
        }

        return false;
    }

    pair<int, int> findMinimumProbability(vector<vector<char>>& board) {
        int minAvailable = 10;
        pair<int, int> pos = {-1, -1};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.')
                    continue;

                vector<int> availableDigits = getAvailableDigits(i, j);
                if (minAvailable > availableDigits.size()) {
                    minAvailable = availableDigits.size();
                    pos = {i, j};
                }
            }
        }
        return pos;
    }

    vector<int> getAvailableDigits(int x, int y) {
        vector<int> availableDigits;
        for (int digit = 1; digit <= 9; ++digit) {
            if (row[x][digit] && col[y][digit] && box[hash(x / 3, y / 3)][digit])
                availableDigits.push_back(digit);
        }
        return availableDigits;
    }
};