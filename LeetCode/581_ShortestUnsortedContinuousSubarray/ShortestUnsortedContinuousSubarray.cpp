// 解法一: 排序, 时间复杂度O(NlogN)
int findUnsortedSubarray(vector<int>& nums) {
		 if (nums.empty()) {
			 return 0;
		 }
		 vector<int> numsCopy(nums);
		 sort(numsCopy.begin(), numsCopy.end());
		 int left = 0;
		 int right = nums.size() - 1;
		 while (left < nums.size() && nums[left] == numsCopy[left]) {
			 ++left;
		 }
		 while (right > left && nums[right] == numsCopy[right]) {
			 --right;
		 }

		 return (right - left + 1);
	 }


// 解法二: 单端扫描, 时间复杂度O(N)
