// 三数之和




// 无重复字符的最长子串
// 使用hash表, 也可以使用队列进行滑动窗口, 进入一个新的元素时将队首元素出队列
int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    vector<int> dp(256, -1);
    int maxLength = 0;
    int curLength = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (dp[s[i]] == -1 || (i - dp[int(s[i])] > curLength)) {
            ++curLength;
        }
        else {
            curLength = i - dp[int(s[i])];
        }
        dp[int(s[i])] = i;
        maxLength = maxLength > curLength ? maxLength : curLength;
    }
    return maxLength;
}
