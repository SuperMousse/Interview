// 给定K个鸡蛋, 还有一栋1~N层的楼, 鸡蛋有破碎的临界层数N,  0 <= F <= N鸡蛋不会破裂, 超过N
// 鸡蛋就会破裂, 每次可以从一个层数X(1 <= X <= N)扔下一个鸡蛋, 返回找到临界层数F的最小扔鸡蛋次数
// Input: K = 1, N = 2, 一个鸡蛋两层楼
// Output: 2
// 分析: dp[m][k]表示给定m次扔鸡蛋和k个鸡蛋, 能够检查的最大层数
//      dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1, dp[m][k]指数级增长到N
//      如果鸡蛋破裂, 该层下面可以有dp[m - 1][k - 1]层
//      如果鸡蛋没有破裂, 该层上面可以有dp[m - 1][k]层
// dp[m][k]可以检查的总层数为当前层上下层数+当前层
// 时间复杂度: O(KlogN)
// 空间复杂度: O(NK)

int superEggDrop(int K, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    int m = 0;
    while (dp[m][K] < N) {
        ++m;
        for (int k = 1; k <= K; ++k)
            dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
    }
    return m;
}
