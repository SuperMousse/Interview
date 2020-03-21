// f[i, j]表示到text1的第i个字符(text1[i-1])和到text2的第j个字符的最长公共子序列长度
// f[i, j] = f(i−1, j−1) + 1            text[i-1] = text[j-1]
// f[i,j] = max(f[i, j−1], f[i−1, j])   text[i-1] != text[j-1]
int longestCommonSubsequence(string text1, string text2) {
	int m = text1.size();
	int n = text2.size();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (text1[i - 1] == text2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[m][n];
}
