// illustration
// index:            [ 0,  1,  2,  3,  4,  5,  6,  7]
// temperature:      [73, 74, 75, 71, 69, 72, 76, 73]
// need temperature: [74, 75, 76, 72, 72, 76, 76, 73]
// nedd inedx:       [ 1,  2,  6,  5,  5,  6,  6,  7]
// result:           [ 1,  1,  4,  2,  1,  1,  0,  0]

// 解法一: 时间复杂度O(NW), 空间复杂度O(N+W), W是T允许的数目
vector<int> dailyTemperatures(vector<int>& T) {
    if (T.empty()) {
        return vector<int>();
    }
    int length = T.size();
    vector<int> result(length, 0);
    vector<int> next(101, INT_MAX);
    for (int i = length - 1; i >= 0; --i) {
        int largerIndex = INT_MAX;
        for (int t = T[i] + 1; t <= 100; ++t) {
            if(next[t] < largerIndex) {
                largerIndex = next[t];
            }
        }
        if (largerIndex < INT_MAX) {
            result[i] = largerIndex - i;
        }
        next[T[i]] = i;
    }
    
    return result;
}

// 解法二: 栈
vector<int> dailyTemperatures(vector<int>& T) {
    if (T.empty()) {
        return vector<int>();
    }
    int length = T.size();
    vector<int> result(length, 0);
    stack<int> stackInt; // stack的栈顶存储了下一个warmer的index
    for (int i = length - 1; i >= 0; --i) {
        // 说明当前天的温度比前一天的温度高, 那么就把一天的温度出栈, 向前一天, 直到
        // 找到warmer的一天, 如果stack为空说明没有warmer的天了
        while (!stackInt.empty() && T[i] >= T[stackInt.top()]) {
            stackInt.pop();
        }
        result[i] = stackInt.empty() ? 0 : stackInt.top() - i;
        stackInt.push(i);
    }

    return result;
}
