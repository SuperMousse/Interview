/ 二维动态规划
// 假设输入数组为{a1, a2, a3, a4, a5}, 其中数字均大于0, 求正负号的和可以转化为找到正、负子数组, 使得其和为S
// 假设正数组为{a1, a2}, 负数组为{a3, a4, a5}
// 则: sum(P) - sum(N) = target
//  => sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N)
//  => 2 * sum(P) = target + sum(nums)
//  转化为寻找子数组,使得sum(P) = (target + sum(nums)) / 2成立,
//  target + sum(nums)必定为偶数, 若为奇数s则找不到子数组成立


int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.empty() || nums.size() > 20 || S > 1000) {
        return 0;
    }
    int sum = 0;
    for(auto num : nums) {
        sum += num;
    }
    // 若sum<S则即使全为正数也无法达到S, 另S+sum必须为偶数
    if(sum < S || ((S + sum) & 0x1) != 0) {
        return 0;
    }

    return helper(nums, (S + sum) / 2);
}

// 二维dp
int helper(vector<int>& nums, int S) {
   int len = nums.size();
   vector<vector<int>> dp(len + 1, vector<int>(S + 1, 0));
   dp[0][0] = 1;
   for (int i = 1; i <= len; ++i) {
       for (int j = 0; j <= S; ++j) {
           if(j >= nums[i - 1]) {
               dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
           }
           else {
               dp[i][j] = dp[i - 1][j];
           }
       }
   }
   return dp[len][S];
}

// 一维dp
int helper(vector<int>& nums, int S) {
   int len = nums.size();
   vector<int> dp(S + 1, 0);
   dp[0] = 1;
   for (int i = 1; i <= len; ++i) {
       for (int j = S; j >= 0; --j) {
           if(j >= nums[i - 1]) {
               dp[j] = dp[j] + dp[j - nums[i - 1]];
           }
       }
   }

   return dp[S];

}
