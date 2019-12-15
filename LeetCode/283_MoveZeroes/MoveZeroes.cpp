void moveZeroes(vector<int>& nums) {
		 if (nums.empty()) {
			 return;
		 }
		 int pos = 0;
		 int length = nums.size();
		 for (int i = 0; i < length; ++i) {
			 if (nums[i] != 0) {
				 nums[pos] = nums[i];
				 ++pos;
			 }
		 }

		 while (pos < length) {
			 nums[pos] = 0;
			 ++pos;
		 }
	 }
