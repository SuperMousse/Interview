int nthUglyNumber(int n) {
    if(n < 1 || n > 1690) {
        return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    int lastIndexOf2 = 0;
    int lastIndexOf3 = 0;
    int lastIndexOf5 = 0;
    for (int nextUglyIndex = 1; nextUglyIndex < n; ++nextUglyIndex) {
        int min = minNum(dp[lastIndexOf2] * 2, dp[lastIndexOf3] * 3, dp[lastIndexOf5] * 5);
        dp[nextUglyIndex] = min;
        if(dp[lastIndexOf2] * 2 == dp[nextUglyIndex]) {
            ++lastIndexOf2;
        }
        if(dp[lastIndexOf3] * 3 == dp[nextUglyIndex]) {
            ++lastIndexOf3;
        }
        if(dp[lastIndexOf5] * 5 == dp[nextUglyIndex]) {
            ++lastIndexOf5;
        }
    }

    return dp[n - 1];
}

int minNum(int a, int b, int c) {
    int result = a < b ? a : b;
    result = result < c ? result : c;
    return result;
}
