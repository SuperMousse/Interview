// 动态规划O(N)解法
int maxSubArray(vector<int>& nums) {
	if (nums.empty()) {
		throw runtime_error("wrong input");
	}

	int length = nums.size();
	int maxSum = nums[0];
	int currentSum = nums[0];

	for (int i = 1; i < length; ++i)
	{
		if (currentSum <= 0) {
			currentSum = nums[i];
		}
		else {
			currentSum += nums[i];
		}

		maxSum = (currentSum > maxSum) ? currentSum : maxSum;
	}

	return maxSum;
}


// Divide and Conquer, 分治法
