Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

1. Insert a character
2. Delete a character
3. Replace a character




// dp[i][j]代表把word1[0..i)转化成为word2[0..j)的最小操作数量
// 初始化dp[i][0] = i and dp[0][j] = j
// dp[i][j] = dp[i - 1][j - 1]  if word1[i - 1] == word2[j - 1]
// dp[i][j] = min(replace, insert, delete) if word1[i - 1] != word2[j - 1]

// replace: 把word1[i - 1]替换为word2[j - 1], dp[i][j] = dp[i - 1][j - 1] + 1
// delete: 如果word1[0..i - 1) = word2[0..j), 表示word1[i - 1]需要删除, dp[i][j] = dp[i - 1][j] + 1
// insert: 如果word1[0..i) + word2[j - 1] = word2[0..j), 表示需要在word1[0..i)后插入word2[j - 1], dp[i][j] = dp[i][j - 1] + 1


int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int replaceOperation  = dp[i - 1][j - 1] + 1;
                int insertOperation = dp[i][j - 1] + 1;
                int deleteOperation = dp[i - 1][j] + 1;
                dp[i][j] = min(insertOperation, min(replaceOperation, deleteOperation));
            }
        }
    }
    return dp[m][n];
}
