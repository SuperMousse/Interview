int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (obstacleGrid[i][j] != 1) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if (i != 0 && j == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
             }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[rows-1][cols-1];
}
