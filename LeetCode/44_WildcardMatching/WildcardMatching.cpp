// 动态规划
// 通配符匹配

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            // 都是空元素， match
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            }
            // s为空， dp[i][j]之前的dp[i][j-1]等都必须是true, 并且p中后续字符必须都是'*', 才为true
            else if (i == 0) {
                dp[i][j] = (p[j-1] == '*' && dp[i][j-1]);
            }
            // p为空, s不为空, false
            else if (j == 0) {
                dp[i][j] = false;
            }
            // s, p都不为空, p[j-1]为'*', 此时可以匹配多个字符, dp[i][j-1]表示s成功匹配一个字符, p不移动
            // dp[i-1][j]表示'*'未匹配任何字符, s没移动, p移动了
            else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            // s, p都不为空, s[i-1]/p[j-1]字符相同成功匹配， 或者p[j-1]为'?'可以匹配任意字符,
            // 此时dp[i][j]依赖于dp[i-1][j-1]
            else if (s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}



