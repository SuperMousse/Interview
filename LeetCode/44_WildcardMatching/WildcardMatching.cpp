// 动态规划
// 通配符匹配

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            int startOfS = i - 1;
            int startOfP = j - 1;
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            }
            else if (i == 0) {
                dp[i][j] = p[startOfP] == '*' && dp[i][j-1];
            }
            else if (j == 0) {
                dp[i][j] = false;
            }
            else if (p[startOfP] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else if (s[startOfS] == p[startOfP] || p[startOfP] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}



