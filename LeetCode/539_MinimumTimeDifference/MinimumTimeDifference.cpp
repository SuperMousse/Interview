
// 给定一个字符串数组表示"小时：分钟", 找到数组中任意两个时间之间的最小值
// Input: ["23:59","00:00"]
// Output: 1
// 分析: 至多只有24 * 60个分钟, 使用mask表示该时间是否出现, 属于桶排序


int findMinDifference(vector<string>& timePoints) {
    vector<bool> mark(24 * 60, false);
    int minTime = INT_MAX;
    int maxTime = INT_MIN;
    for (string t : timePoints) {
        int pos = t.find(':');
        int hour = stoi(t.substr(0, pos));
        int minute = stoi(t.substr(pos+1));
        if (mark[hour * 60 + minute] == true) {
            return 0;
        }
        minTime = min(minTime, hour * 60 + minute);
        maxTime = max(maxTime, hour * 60 + minute);
        mark[hour * 60 + minute] = true;
    }
    int minDiff = INT_MAX;
    int prevTime = minTime;
    for (int i = minTime; i <= maxTime; ++i) {
        if (mark[i] == true) {
            if (i == minTime) {
                // 0---minTime---maxTime---1440, minDiff可能在minTime, maxTime之间
                // 也有可能需要maxTime---1440---0---minTime转一圈
                minDiff = min(minDiff, min(maxTime - minTime, 1440 - maxTime + minTime));
            }
            else {
                // minTime---prev---i---maxTime
                minDiff = min(minDiff, i - prevTime);
            }
            prevTime = i;
        }
    }
    return minDiff;
}
