// 解法一: 对0，1，2出现的次数计数，然后覆盖重写


// 解法二: 维护首尾双指针，移动双指针进行交换
  void sortColors(vector<int>& nums) {
      if(nums.empty()){
          return;
      }
      int length = nums.size();
      int left = 0;
      int right = length - 1;
      for (int i = 0; i <= right; ++i) {
          if(nums[i] == 0) {
              swap(nums[i--], nums[left++]); // 注意需要i--，因为交换过去了新的元素之后需要重新考虑当前元素
          }
          else if(nums[i] == 2) {
              swap(nums[i--], nums[right--]);
          }
          else {
              continue;
          }

      }
      return;
  }

//
