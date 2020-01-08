// dp[i]表示了第i个字符的位置上是否为一个word
// dp[i]为true, 而且i~j之间又构成了一个word, 则dp[j]为true
// 因此对于每个i, 向前搜索每个位置上的dp, 找到一个true之后判断这之间是否构成了一个word

bool wordBreak(string s, vector<string>& wordDict) {
    if(s.empty() || wordDict.empty()) {
        return false;
    }
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if(dp[j] == true) {
                string word = s.substr(j, i - j); // j为起始位置, i-j为substr长度
                if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[s.size()];
}
