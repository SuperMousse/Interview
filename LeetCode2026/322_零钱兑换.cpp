class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0) {
            return -1;
        }
        // f(n) = min_{j=0}^{len-1}{f(n - c_j) + 1}, f(n)表示组成金额n的最少硬币数量
        vector<int> dp(amount+1, amount+1);
        int len = coins.size();
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int min_value = amount+1;
            for (int j = 0; j < len; j++) {
                if ((i - coins[j]) >= 0) {
                    min_value = min(min_value, dp[i - coins[j]] + 1);
                    //dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
            dp[i] = min_value;
        }
        // 大于amount说明
        return dp[amount] == (amount+1) ? -1 : dp[amount];
    }
};
