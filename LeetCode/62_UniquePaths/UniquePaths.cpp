// 时间复杂度O(M*N)

int uniquePaths(int m, int n) {
    if(m <= 0 || n <= 0) {
        return 0;
    }
    vector<vector<int> > dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0 && j == 0) {
                continue;
            }
            int top = 0;
            int left = 0;
            top = j > 0 ? dp[i][j - 1] : 0;
            left = i > 0 ? dp[i - 1][j] : 0;
            dp[i][j] = top + left;
            
        }
    }
    return dp[m - 1][n - 1];
}
