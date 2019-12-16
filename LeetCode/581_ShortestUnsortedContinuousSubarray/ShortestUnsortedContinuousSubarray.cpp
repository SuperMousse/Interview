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


// 解法二: 双端扫描, 时间复杂度O(N)
 int findUnsortedSubarray(vector<int>& nums) {
		 if (nums.empty()) {
			 return 0;
		 }
		 int left = 0;
		 int right = nums.size() - 1;

		 // nums[0, i - 1] and nums[j + 1, n - 1] are both sorted.
		 while (left < right && nums[left] <= nums[left + 1]) { 
			 ++left;
		 }
		 if (left >= right) {
			 return 0;
		 }
		 while (nums[right] >= nums[right - 1]) {
			 --right;
		 }
		 int max = INT_MIN;
		 int min = INT_MAX;

		 for (int i = left; i <= right; ++i) {
			 max = max > nums[i] ? max : nums[i];
			 min = min < nums[i] ? min : nums[i];
		 }
		 // nums[i - 1] <= min && max <= nums[j + 1], where min and max are the minimum and maximum values of subarray nums[i, j].
		 while (left >= 0 && min < nums[left]) {
			 --left;
		 }
		 while (right < nums.size() && nums[right] < max) {
			 ++right;
		 }
		 // [left + 1, right - 1]闭区间为需要排序区间
		 return (right - left - 1);
	 }
