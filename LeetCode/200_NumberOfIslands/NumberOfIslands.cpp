// dfs, 依次遍历每一个元素, 并且对于每一个元素进行dfs递归, 发现连通的元素就将其values置为'0'
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) {
        return 0;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    vector<vector<char>> g(grid);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(g[i][j] == '1') {
                dfs(g, i, j, rows, cols);
                ++count;
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
    if(row<0 || col < 0 || row >= rows || col >= cols || grid[row][col] == '0') {
        return;
    }
    grid[row][col] = '0';
    dfs(grid, row + 1, col, rows, cols);
    dfs(grid, row - 1, col, rows, cols);
    dfs(grid, row, col - 1, rows, cols);
    dfs(grid, row, col + 1, rows, cols);
    return;
}
