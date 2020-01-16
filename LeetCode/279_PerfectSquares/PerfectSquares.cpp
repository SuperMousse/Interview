// 动态规划, dp[i]表示i至少需要几个完全平方数构成
// 分析思路与数字由多少个硬币组成相同
// dp[i] = min(dp[i - c] + 1), c是小于i的所有完全平方数

int numSquares(int n) {
    if(n <= 0) {
        return 0;
    }
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
