// m * n的grid, 每个cell中存储的正整数表示金子的数量, 返回能够收集的最大金子数量
// 1. 每次访问可以拿走cell中的全部金子
// 2. 每次可以向上、下、左、右四个方向行走
// 3. 不能重复访问同一个cell
// 4. 不访问金子数量为0的cell
// 5. 可以在任意位置停止访问grid

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
// [5,8,7],
// [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    int curGold = 0;
                    curGold = dfs(grid, rows, cols, i, j, curGold);
                    maxGold = max(maxGold, curGold);
                }
            }
        }
        return maxGold;
    }

    int dfs(vector<vector<int>>& grid, int rows, int cols, int i, int j, int curGold) {
        if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != 0) {
            int temp = grid[i][j];
            curGold += grid[i][j];
            int maxGold = curGold;

            grid[i][j] = 0; // 通过把grid[i][j]置0的方式避免重复访问
            maxGold = max(maxGold, dfs(grid, rows, cols, i + 1, j, curGold));
            maxGold = max(maxGold, dfs(grid, rows, cols, i - 1, j, curGold));
            maxGold = max(maxGold, dfs(grid, rows, cols, i, j + 1, curGold));
            maxGold = max(maxGold, dfs(grid, rows, cols, i, j - 1, curGold));

            grid[i][j] = temp; // 恢复grid[i][j]的数值

            return maxGold;
        }
        return curGold;
    }
};
