// 最长回文子串

// dp[i][j]表示i,j位置上是否是回文的
int longestPalindromicSubsequence(string s) {
    if (s.empty()) {
        return 0;
    }
    int length = s.size();
    int maxLength = 1;
    vector<vector<bool> > dp(length, vector<bool>(length, false));
    // if s[i] == s[j], j - i <= 1, dp[i][j] = true, j > i
    // if s[i] == s[j], j - i > 1, dp[i][j] = dp[i+1][j-1]
    // if s[i] != s[j], dp[i][j] = false
    for (int i = length - 1; i >= 0; --i) {
        for (int j = i; j < length; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = j - i > 1 ? dp[i + 1][j - 1] : true;
            }
            else {
                dp[i][j] = false;
            }
            if(dp[i][j]) {
                int curLength = j - i;
                maxLength = maxLength > curLength ? maxLength : curLength;
            }
        }
    }
    return maxLength;
}


// 最长增长子序列
