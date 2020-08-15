// 输出字符串, 返回最长的有效匹配括号
// Input: ")()()(())"
// Output: 8
// 解释: 最长的有效括号匹配是"()()(())"
// dp[i]表示到[0, i]的最长有效匹配括号
// if s[i] = '(', 令dp[i]=0, 因为任何以'('截止的字符串都不是有效的
// if s[i] = ')',
//     if s[i-1] = '(', dp[i] = dp[i-2] + 2, 发现一组有效的匹配'()', len + 2
//     if s[i-1] = ')' and s[i - dp[i-1] - 1] = '(', dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2],
//         s[i - dp[i-1] -1]表示i-1这一组匹配之前的'(', 用于和s[i]=')'匹配;
//         dp[i-1] + 2表示和i-1位置上的连上了, 找到了一组新的匹配, dp[i - dp[i-1] - 2]表示i-1的前一组匹配,
//         检查是否和前一组匹配连上

int longestValidParentheses(string s) {
    if (s.size() <= 1) {
        return 0;
    }
    int length = s.size();
    int maxLen = 0;
    vector<int> dp(length, 0);
    for (int i = 1; i < length; ++i) {
        if (s[i] == ')') {
            if (s[i-1] == '(') {
                // prevent '()' at first
                dp[i] = ((i-2) >= 0) ? (dp[i-2] + 2) : 2;
                maxLen = max(maxLen, dp[i]);
            }
            else  {
                // if s[i-1] == ')', combine the previous length.
                if((i - dp[i-1] - 1 >= 0) && s[i - dp[i-1] - 1] == '('){
                    dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i - dp[i-1] - 2] : 0);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        else {
            // s[i] = '(', skip because dp[i] is initialized with 0
            continue;
        }
    }
    return maxLen;
}
