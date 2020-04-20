Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
 
 void rotate(vector<int>& nums, int k) {
      int length = nums.size();
      k = k % length;
      reverse(nums.begin(), nums.begin() + length - k);
      reverse(nums.begin() + length - k, nums.end());
      reverse(nums.begin(), nums.end());
      return;
  }
