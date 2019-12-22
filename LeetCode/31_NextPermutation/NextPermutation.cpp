	 void nextPermutation(vector<int>& nums) {
		 if (nums.empty()) {
			 return;
		 }
		 // 找到第一个不是递减的数字
		 int i = nums.size() - 2;
		 while (i >= 0 && nums[i + 1] <= nums[i]) {
			 --i;
		 }
		 // 如果存在比当前数字更大的数字, 由于i的右侧为一个递减数组, 所以比其大的下一个数字只能是将i换为其右侧中比它大一点的数字
		 if (i >= 0) {
			 int j = nums.size() - 1;
			 while (j >= 0 && nums[j] <= nums[i]) {
				 --j;
			 }
			 swap(nums[i], nums[j]);
		 }
		 reverse(nums, i + 1);
	 }

	 void reverse(vector<int>& nums, int start) {
		 int i = start;
		 int j = nums.size() - 1;
		 while (i < j) {
			 swap(nums[i], nums[j]);
			 ++i;
			 --j;
		 }
	 }
