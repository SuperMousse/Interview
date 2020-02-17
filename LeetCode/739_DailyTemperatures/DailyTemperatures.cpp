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
