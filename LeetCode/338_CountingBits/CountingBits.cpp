// 时间复杂度O(N), 空间复杂度O(N)
// 利用x和x/2除了最后一位都相同的特点
 vector<int> countBits(int num) {
   vector<int> result(num + 1, 0);
   for (int i = 1; i <= num; ++i)
   {
     result[i] = result[i >> 1] + (i & 0x1);
   }
   return result;
 }
