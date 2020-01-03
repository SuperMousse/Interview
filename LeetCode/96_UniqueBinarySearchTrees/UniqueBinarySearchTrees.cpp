// 动态规划
// dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] +...+ dp[i-1]*dp[0]

int numTrees(int n) {
        if(n < 1) {
            return -1;
        }
        int* dp = new int[n + 1]; // dp[0], ... dp[n]
        memset(dp, 0, (n + 1) * sizeof(int));
        
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            // dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] +...+ dp[i-1]*dp[0]
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
}
