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
// 时间复杂度O(NlogN)

// 最大子数组一定为中点左侧最大子数组, 中点右侧最大子数组, 跨越中点的所有子数组之中的一个
int maxSubArray(vector<int>& nums) {
	return maxSubArray(nums, 0, nums.size() - 1);
}

int maxSubArray(vector<int> & nums, int left, int right) {
	if (left > right) {
		return INT_MIN;
	}
	int middle = left + (right - left) / 2;
	int middleLeft = 0;
	int middleRight = 0;
	int leftMax = maxSubArray(nums, left, middle - 1);
	int rightMax = maxSubArray(nums, middle + 1, right);

	// the maximum subarray spans the two halves
	// starting from the middle element and move to both ends
	// the max subarray on the left
	for (int i = middle - 1, sum = 0; i >= left; --i) {
		sum += nums[i];
		middleLeft = max(sum, middleLeft);
	}
	for (int i = middle + 1, sum = 0; i <= right; ++i) {
		sum += nums[i];
		middleRight = max(sum, middleRight);
	}
	// left sub array VS right sub array VS cross sub array
	int crossMax = middleLeft + middleRight + nums[middle];
	return max(max(leftMax, rightMax), crossMax);
}
