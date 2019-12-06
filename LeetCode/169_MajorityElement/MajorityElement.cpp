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
