// 核心思想： f(n) = max(f(n-2)+currentValue, f(n-1)) 

// 递归动态规划, 使用memory
 int rob(vector<int>& nums) {
   if (nums.empty()) {
     return 0;
   }
   vector<int> memory(nums.size(), -1);
   return rob(nums, memory, nums.size() - 1);
 }

 int rob(vector<int>& nums, vector<int>& memory, int pos) {
   if (pos < 0) {
     return 0;
   }
   if (memory[pos] >= 0) {
     return memory[pos];
   }
   int previous2 = rob(nums, memory, pos - 2) + nums[pos];
   int previsou1 = rob(nums, memory, pos - 1);
   int result = max(previous2, previsou1);
   memory[pos] = result;
   return result;
 }


// 循环动态规划, 斐波那契数列变种
 int rob(vector<int>& nums) {
		 if (nums.empty()) {
			 return 0;
		 }
		 int previous1 = 0;
		 int previous2 = 0;
		 int current = 0;
		 for (int i = 0; i < nums.size(); ++i) {
			 current = max(previous2 + nums[i], previous1);
			 previous2 = previous1;
			 previous1 = current;
		 }

		 return current;
	 }
