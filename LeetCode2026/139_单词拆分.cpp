/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }
        unordered_set<string> wordSet;
        for (int i = 0; i < wordDict.size(); i++) {
            wordSet.insert(wordDict[i]);
        }
        int len = s.size();
        // dp[i]表示0~i-1个字符串能否被wordDict所表示
        // dp[i] = dp[j] && check(s[j:i-1])
        // dp[j]就是遍历小于i的每一个字符，获取状态，同时再看j后面的字符是否在wordDisct里面，如果成立直接判断为true
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < i; j++) {
                string tmp = s.substr(j, i-j); // 需要注意j是起始符位置，i-j是长度
                if (dp[j] == true && wordSet.find(tmp) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
