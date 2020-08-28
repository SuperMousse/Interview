// 注意本题是完全背包问题
int waysToChange(int n) {
    if (n < 0) {
        return 0;
    }
    int mod = 1000000007;
    vector<int> coins = {1, 5, 10, 25};
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j >= coins[i]) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
            }
        }
    }
    return dp[n];
}
