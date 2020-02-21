// dp[i]表示i位置上的最长增长子序列
// 注意此处的增长子序列没有要求连续, 所以才向前查找所有小于dp[i]的j
// dp[i] = max(dp[j]) + 1, j \in [0, i)
// result = max(dp[i]), i \in [0, n)
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int length = nums.size();
    int maxLength = 1;
    vector<int> dp(length, 0);
    dp[0] = 1;
    for(int i = 1; i < length; ++i) {
        int maxVal = 0;
        for(int j = 0; j < i; ++j) {
            if(nums[i] > nums[j]) {
                maxVal = (maxVal > dp[j]) ? maxVal : dp[j];
            }
        }
        dp[i] = maxVal + 1;
        maxLength = (maxLength > dp[i]) ? maxLength : dp[i];
    }
    return maxLength;
}
