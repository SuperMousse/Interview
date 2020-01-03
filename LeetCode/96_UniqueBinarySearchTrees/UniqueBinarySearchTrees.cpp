// 动态规划
// 依次选取每一个数字为根节点，所有的二叉搜索树组合为左子树组合*右子树组合之和
// {1, 2, 3, 4, 5}
// 选取1为根节点, 然后左子树0个数字, 右子树4个数字->dp[0]*dp[4]
// 选取2为根节点, 左子树1个数字, 右子树3个数字->dp[1]*dp[3]
// dp[5]=dp[0]*dp[4] + dp[1]*dp[3] + dp[2]*dp[2] + dp[3]*dp[1] + dp[4]*dp[0]
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
