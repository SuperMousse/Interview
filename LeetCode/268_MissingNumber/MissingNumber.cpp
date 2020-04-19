数组有N个数字， 范围是0~n, 找到其中缺失的数字

0 ~ n的和 - 所有数字加起来， 其中0 ~ n的和 = 1~n的和

  int missingNumber(vector<int>& nums) {
      int len = nums.size();
      int res = 0;
      for (size_t i = 0; i < len; ++i) {
          res += (i + 1) - nums[i];
      }
      return res;
  }
