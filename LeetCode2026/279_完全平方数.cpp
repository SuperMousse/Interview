/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
*/

class Solution {
public:
    int numSquares(int n) {
        // f(n)表示需要多少个数的平方来表示整数n，且这些数都位于[1, sqrt(n)]
        // f(n) = 1 + min_{j=1}^{sqrt(n)}f[n - j^2]，j表示在所有1~sqrt(n)的范围内搜索到的最小值
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int minCount = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minCount = min(minCount, dp[i - j*j]);
            }
            dp[i] = minCount + 1;
        }
        return dp[n];
    }
};
