
// dp[i]表示扫描数组过程中, 扫描到当前数字时, 选取的模3为i的最大数字之和
// 若 nums[i] % 3 = 1. 则nums[i] + dp[2]就可以让 当前数字总和 % 3 = 0
// 即 dp[0] = max(dp[0], nums[i] + dp[2]) if nums[i] % 3 = 1

// a: if mod=0, dp[0]=max(dp[0], dp[0]+nums[i])
//    if mod=1, dp[0]=max(dp[0], dp[2]+nums[i])
//    if mod=2, dp[0]=max(dp[0], dp[1]+nums[i]) => dp[(3 + 0 - mod) % 3] + nums[i]

// b: if mod=0, dp[1]=max(dp[1], dp[1]+nums[i])
//    if mod=1, dp[1]=max(dp[1], dp[0]+nums[i])
//    if mod=2, dp[1]=max(dp[1], dp[2]+nums[i]) => dp[(3 + 1 - mod) % 3] + nums[i]

int maxSumDivThree(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> dp(3, 0);
    for (int i = 0; i < nums.size(); ++i) {
        int mod = nums[i] % 3;
        int a = dp[(3 + 0 - mod) % 3];
        int b = dp[(3 + 1 - mod) % 3];
        int c = dp[(3 + 2 - mod) % 3];

        if (a != 0 || mod == 0) dp[0] = max(dp[0], a + nums[i]);
        if (b != 0 || mod == 1) dp[1] = max(dp[1], b + nums[i]);
        if (c != 0 || mod == 2) dp[2] = max(dp[2], c + nums[i]);
    }
    return dp[0];
}
