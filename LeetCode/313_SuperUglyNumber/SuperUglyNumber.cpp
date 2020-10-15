// 方法一： 时间复杂度O(kN), 采用循环进行多次比较
int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n < 0 || n > 1000000 || primes.size() > 100) {
        return 0;
    }
    int k = primes.size();
    vector<int> dp(n, 0);
    vector<int> lastIndex(k, 0);
    dp[0] = 1;

    for (int nextUglyIndex = 1; nextUglyIndex < n; ++nextUglyIndex) {
        int minNum = INT_MAX;
        for (int i = 0; i < k; ++i) {
            minNum = min(minNum, dp[lastIndex[i]] * primes[i]);
        }
        dp[nextUglyIndex] = minNum;
        for (int i = 0; i < k; ++i) {
            if(dp[lastIndex[i]] * primes[i] == dp[nextUglyIndex]) {
                ++lastIndex[i];
            }
        }
    }
    return dp[n - 1];
}

// 方法二: 时间复杂度O(log(k)N), 采用最小堆进行大小比较
