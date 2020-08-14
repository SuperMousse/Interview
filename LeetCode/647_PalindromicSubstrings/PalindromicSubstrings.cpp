// dp[i][j]表示i~j是否是一个回文子串
// 原理同最长回文子串

    int countSubstrings(string s) {
        if(s.size() <= 0 || s.size() > 1000) {
            return 0;
        }
        int count = 0;
        int length = s.size();
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        for (int i = length - 1; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                // if s[i] == s[j] j - i <= 1, dp[i][j] = true
                // if s[i] == s[j] j - i > 1 ==> dp[i][j] = dp[i+1][j-1]
                // if s[i] != s[j] dp[i][j] = false;
                if(s[i] == s[j]) {
                    dp[i][j] = (j - i <= 1) ? true : dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
                if(dp[i][j] == true) {
                    ++count;
                }
            }
        }
        return count;
    }
