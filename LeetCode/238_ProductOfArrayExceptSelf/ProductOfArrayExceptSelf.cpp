 // 若输入为 a1,       a2,       a3,       a4,       a5
 // 结果为:  a2a3a4a5, a1a3a4a5, a1a2a4a5, a1a2a3a5, 
 // 分解为:  1*        a1*       a1a2*     a1a2a3*   a1a2a3a4*
 //          a2a3a4a5, a3a4a5,   a4a5,     a5,       1 

 vector<int> productExceptSelf(vector<int>& nums) {
   if (nums.empty()) {
     return vector<int>();
   }
   int length = nums.size();
   vector<int> result(length, 1);
   result[0] = 1;
   for (int i = 1; i < length; ++i) {
     result[i] = result[i - 1] * nums[i - 1];
   }
   int temp = 1;
   for (int i = length - 1; i >= 0; --i) {
     result[i] = result[i] * temp;
     temp = temp * nums[i];
   }
   return result;

 }
