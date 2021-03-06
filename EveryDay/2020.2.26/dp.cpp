
// 最大连续乘积子数组
// maxProduct = max(nums[i]*maxProduct, nums[i])
// 需要注意这里, 因为要求是连续子数组, 所以一个数字在新的位置上要么乘上去, 要么重新开始
int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int maxRes = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i] > 0) {
            maxProduct = max(nums[i]*maxProduct, nums[i]);
            minProduct = min(nums[i]*minProduct, nums[i]);
        }
        else {
            int temp = maxProduct;
            maxProduct = max(nums[i]*minProduct, nums[i]);
            minProduct = min(nums[i]*temp, nums[i]);
        }
        maxRes = max(maxRes, maxProduct);
    }
    return maxRes;
}

// 找零钱
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
// dp[i] 表示价钱i的最少找钱数目
// dp[i] = min(dp[i], dp[i - coins[j]] + 1) coins[j] <= i
 int coinChange(vector<int>& coins, int amount) {
    if (coins.empty() || amount < 0) {
        return -1;
    }
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        int temp = 0;
        for (int j = 0; j < coins.size(); ++j) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return (dp[amount] < amount + 1) ? dp[amount] : -1;
}


