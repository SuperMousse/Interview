// 铺瓷砖
// 给定矩形 n * m, 找到至少需要多少块正方形瓷砖能够将矩形填满
// n = 2, m = 3, res = 3, 2块 1 * 1, 1块 2 * 2

int tilingRectangle(int n, int m) {
      unordered_map<long, int> hash;
      vector<int> height(n+1, 0);
      int minCount = INT_MAX;
      if (n == m) {
          return 1;
      }
      if (n > m) {
          dfs(m, n, height, hash, 0, minCount);
      }
      else {
          dfs(n, m, height, hash, 0, minCount);
      }
      return minCount;
  }

void dfs(int n, int m, vector<int> height, unordered_map<long, int>& hash, int curCount, int& minCount) {
    if (curCount >= minCount) {
        return;
    }
    bool isFull = true;
    int pos = -1;
    int minHeight = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (height[i] < m) {
            isFull = false;
        }
        if (height[i] < minHeight) {
            pos = i;
            minHeight = height[i];
        }
    }
    if (isFull) {
        minCount = min(curCount, minCount);
        return;
    }
    long key = 0, base = m + 1;
    for (int i = 1; i <= n; ++i) {
        key += height[i] * base;
        base *= m + 1;
    }
    if (hash.count(key) && hash[key] <= curCount) {
        return;
    }
    hash[key] = curCount;

    int end = pos;
    while (end + 1 <= n && height[end + 1] == height[pos] && (end + 1 - pos + 1 + minHeight) <= m) {
        ++end;
    }

    for (int j = end; j >= pos; j--) {
        int curH = j - pos + 1;

        vector<int> next(height);
        for (int k = pos; k <= j; k++) {
            next[k] += curH;
        }
        dfs(n, m, next, hash, curCount + 1, minCount);
    }
}
