// 给定二维数组, 其中0表示岛屿, 1表示水, 封闭岛屿表示上下左右四周都是1所围成的区域, 返回封闭岛屿数目
// Input: grid = [
//               [1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
// Output: 2

// 分析: 因为封闭岛屿要求四周都是1, 那么grid四周的位置就都不可能是封闭岛屿, 只有可能是封闭岛屿的外缘
// 把grid四周的点作为起点开始遍历, 如果当前位置为0, 就把四周能访问的都置1, 把所有能访问的位置都置1
// 通过这种方式, 只有四周都是1的点才会被留下依旧保持0

class Solution {
public:
    int closedIsland(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // flood fill
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || j == 0 || (i == grid.size() - 1) || (j == grid[0].size() - 1)) {
                    fill(grid, i, j, rows, cols);
                }
            }
        }
        // fill后在遍历, 检测到0就把周围的点都置1
        int result = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    ++result;
                    fill(grid, i, j, rows, cols);
                }
            }
        }
        return result;
    }

    void fill(vector<vector<int>> &grid, int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;
        fill(grid, i+1, j, rows, cols);
        fill(grid, i, j+1, rows, cols);
        fill(grid, i-1, j, rows, cols);
        fill(grid, i, j-1, rows, cols);
        return;
    }
};
