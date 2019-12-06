// 投票法， 
int majorityElement(vector<int>& nums) {
		 if (nums.empty()) {
			 throw runtime_error("wrong input");
		 }
		 int candidate = INT_MAX;
		 int count = 0;
		 for (int num : nums) {
			 if (count == 0) {
				 candidate = num;
			 }
			 if (num == candidate) {
				 ++count;
			 }
			 else {
				 --count;
			 }
		 }
		 return candidate;
	 }
   
 // Partition
int majorityElement(vector<int>& nums) {
	if (nums.empty()) {
		throw runtime_error("wrong input");
	}
	int begin = 0;
	int end = nums.size() - 1;
	int middle = (begin + end) / 2;
	int index = partition(nums, begin, end);

	while (index != middle) {
		if (index > middle) {
			end = index - 1;
		}
		else {
			begin = index + 1;
		}
		index = partition(nums, begin, end);
	}

	return nums[middle];
}

int partition(vector<int>& nums, int begin, int end) {
	if (nums.empty() || begin > end) {
		throw runtime_error("wrong input");
	}
	int left = begin;
	int right = end;
	int base = begin;
	while (true) {
		while (nums[right] >= nums[base] && left < right) {
			--right;
		}
		while (nums[left] <= nums[base] && left < right) {
			++left;
		}
		if (left == right) {
			break;
		}
		int temp = nums[right];
		nums[right] = nums[left];
		nums[left] = temp;
	}

	int temp = nums[left];
	nums[left] = nums[base];
	nums[base] = temp;

	return left;

}
