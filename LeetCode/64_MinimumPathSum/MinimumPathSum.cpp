// 二维动态规划
// 左侧边和上侧边的位置上选取输入数组的值
// 其余位置上选取当前位置上侧和左侧位置中的较小值+当前位置的值
int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty()) {
        return 0;
        
    }
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int> > dp(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }
            else if (i == 0 && j != 0) {
                dp[i][j] = dp[i][j- 1] + grid[i][j];
            }
            else if(i != 0 && j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j- 1]) + grid[i][j];
            }
        }
    }
    
    return dp[rows - 1][cols - 1];
}
