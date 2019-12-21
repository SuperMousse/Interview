// 全排列
 vector<vector<int>> permute(vector<int>& nums) {
   vector<vector<int> > result;
   if (nums.empty()) {
     return result;
   }
   int begin = 0;
   vector<int> temp(nums);
   permuteCore(result, temp, begin);
   return result;
 }

 void permuteCore(vector<vector<int> >& result, vector<int> temp, int begin) {
   if (begin == temp.size() - 1) {
     result.push_back(temp);
     return;
   }
   for (int i = begin; i < temp.size(); ++i)
   {
     swap(temp[i], temp[begin]);
     permuteCore(result, temp, begin + 1);
     swap(temp[i], temp[begin]);
   }
   return;
 }
