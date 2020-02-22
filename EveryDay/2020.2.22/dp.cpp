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
// dp[i]表示i位置上的最长增长子序列
int longestIncreasingSubsequence(vector<int> nums) {
    if (nums.empty()) {
        return 0;
    }
    int length = nums.size();
    int maxLength = 1;
    vector<int> dp(length, -1);
    dp[0] = 1;
    // dp[i] = max(dp[j]) + 1, j \in [0, i)
    // result = max(dp[j]), j \in [0, n)
    for (int i = 0; i < length; ++i) {
        int maxValue = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                maxValue = maxValue > dp[j] ? maxValue : dp[j];
            }
        }
        dp[i] = maxValue + 1;
        maxLength = maxLength > dp[i] ? maxLength : dp[i];
    }
    return maxLength;
}
