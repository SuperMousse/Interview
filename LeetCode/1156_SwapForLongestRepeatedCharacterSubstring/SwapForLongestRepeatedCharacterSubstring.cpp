// 给定一个字符串, 可以交换字符串中的两个字符, 找到交换后的最长连续重复子串

// Input: text = "ababa"
// Output: 3
// Explanation: 交换第一个'b'和最后一个'a', 或者交换最后一个'b'和第一个'a', 之后的最长连续重复子串为'aaa', 返回3
// 分析: group and count
// 时间复杂度O(N), 空间复杂度O(N)


int maxRepOpt1(string text) {
    int len = text.size();
    int maxLength = 1;
    vector<vector<int> > index(26, vector<int>());
    for (int i = 0; i < len; ++i) {
        index[text[i] - 'a'].push_back(i); // index[i]中存储了字符串中所有 char -'a'= i的字符的索引
    }
    for (int i = 0; i < 26; ++i) {
        int consecutiveCount = 1; // 连续字符
        int prevConsecutiveCount = 0;
        int curLength = 0;
        // 查找相同字符的每一个索引
        for (int j = 1; j < index[i].size(); ++j) {
            if (index[i][j] == index[i][j - 1] + 1) {
                ++consecutiveCount; // 相同字符, 索引连续, ++count
            }
            else {
                // 相同字符, 如果索引间隔大于2, 把prevCount=0, count=1
                //         如果索引间隔为1, prevCount=count, count=1
                prevConsecutiveCount = index[i][j] == index[i][j - 1] + 2 ? consecutiveCount : 0;
                consecutiveCount = 1;
            }
            curLength = max(curLength, prevConsecutiveCount + consecutiveCount);
        }
        // 如果实际的字符比curLength多, 那么可以通过swap操作+1
        maxLength = max(maxLength, curLength + (index[i].size() > curLength ? 1 : 0));
    }
    return maxLength;
}
