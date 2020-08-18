// 给定字符串s, 每次操作可以在字符串的任意位置插入任意字符, 返回使得字符串变为回文的最少操作次数
// 分析: dp[i][j]表示 s1: [0, i-1], s2: [0, j-1]的最长公共子序列
//                   s1的第i个字符, s2的第j个字符
// 从字符串的左右两侧同时开始计算最长公共子序列, len-最长公共子序列就是需要插入的元素, 因为公共子序列反序之后是对称的,
// 只需要插入不对称的元素即可
// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

int minInsertions(string s) {
    int len = s.size();
    vector<vector<int> > dp(len + 1, vector<int>(len + 1, 0));
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            // s从左数的第i个字符和s从右数的第j个字符相等
            if (s[i-1] == s[len-j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return len-dp[len][len];
}
