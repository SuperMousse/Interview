// 两次扫描  
// 从左向右扫描, 维护max值, 发现当前值小于max, 则位于无序区间内, 为last, 否则更新max  
// 从右向左扫描, 维护min值, 发现当前值小于min, 则位于无序区间内, 为first, 否则更新min  
// 最终结果为[first, last]  

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


// 解法三: 双端扫描, 一次完成
int findUnsortedSubarray(vector<int>& nums) {
		 if (nums.empty()) {
			 return 0;
		 }
		 int i = 0, j = -1;
		 int min = INT_MAX;
		 int max = INT_MIN;
		 // 实际两次扫描进行了融合
		 // j扫描最大索引, 使得其后都是递增顺序
		 // i扫描最小索引, 使得其前都是递减顺序
		 for (int left = 0, right = nums.size() - 1; right >= 0; ++left, --right) {
			 max = max > nums[left] ? max : nums[left];
			 if (nums[left] != max) {
				 j = left;
			 }

			 min = min < nums[right] ? min : nums[right];
			 if (nums[right] != min) {
				 i = right;
			 }
		 }
		 return (j - i + 1);
	 }
