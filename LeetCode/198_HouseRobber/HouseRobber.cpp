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


// 循环动态规划
