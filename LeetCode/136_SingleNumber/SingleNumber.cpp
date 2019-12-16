
	// 位运算
  int singleNumber(vector<int>& nums) {
		 if (nums.empty()) {
			 throw runtime_error("something goes wrong");
		 }
		 int res = 0;
		 for (size_t i = 0; i < nums.size(); ++i)
		 {
			 res ^= nums[i];
		 }
		 return res;
	}

// 哈希
