// 解法一: 动态规划

// dp[i][j]表示到第i个位置为止, 和为j的子数组的个数
// dp[i][j]有i-1状态的不同j组成, 所以要将i-1减掉后才退化成前一状态
// dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]], j >= nums[i-1]
// dp[i][j] = dp[i-1][j], j < nums[i-1]
// leetcode testcase太多, 使用bool表示dp[i][j]表示到第ie个位置为止, 和为je的子数组z是否存在

// 寻找子数组使得sum(P) = sum(all) / 2;
// sum(all)奇数则不存在, 偶数则转化为子数组
bool canPartition(vector<int>& nums) {
    if (nums.empty()) {
        return true;
    }
    int sum = 0;
    for (auto i : nums) {
        sum += i;
    }
    if (sum & 0x1) {
        return false;
    }
    return helper(nums, sum >> 1);
}
bool helper(vector<int>& nums, int target) {
    if (nums.empty()) {
        return true;
    }
    int length = nums.size();
    vector<vector<bool> > dp(length + 1, vector<bool>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= length; ++i) {
        for (int j = 0; j <= target; ++j) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[length][target];
}


// 解法二: 位运算

