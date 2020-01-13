// F(S) - minimum number of coins needed to make change for amount S using coin denominations
// F(S)表示对于面值S所需要的最少硬币数目, F(s-c_i)表示去掉一枚c_i硬币后, 其硬币数目+1, 并跳转到F(S-c_i)状态
// F(S) = 0, when S = 0
// F(S) = minF(S - c_i) + 1, i = 0, 1, ..., n-1, where S - c_i >= 0
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty() || amount < 0) {
            return -1;
        }
        vector<int> dp(amount + 1, amount + 1); // 最小的硬币为1, 最多需要amount个1, 不可能需要amount+1个硬币
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if(coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; // 若dp[amount]>amout表示其状态仍为初始状态, 该状态不可达
    }
};
