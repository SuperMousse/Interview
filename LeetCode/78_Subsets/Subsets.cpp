// 解法一: 回溯法(递归)
// 关键: 使用堆栈记录加入的元素，返回上一层递归时出栈

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.empty()) {
            return result;
        }
        int length = nums.size();
        vector<int> temp;
        subsetsCore(nums, result, temp, length, 0);
        
        sort(result.begin(), result.end());
        
        return result;
    }

    void subsetsCore(vector<int>& nums, vector<vector<int> >& result, vector<int>& temp,
                     int length, int begin) {
        result.push_back(temp);

        for (int i = begin; i < length; ++i) {
            temp.push_back(nums[i]);
            subsetsCore(nums, result, temp, length, i + 1);
            temp.pop_back();
        }

        return;
    }
    
  // 解法二: 循环法
  // 先求出C(1, 0) + C(1, 1)的所有组合
  // 然后加入新的元素变为C(2, 0)+C(2, 1)+C(2, 2)的所有组合
  // 依次进行
      vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result={{}};
        if(nums.empty()) {
            return result;
        }
        for(int num : nums) {
            int length = result.size();
            for(int i = 0; i < length; ++i) {
                result.push_back(result[i]);
                result.back().push_back(num);
            }
            
        }

        sort(result.begin(), result.end());
        
        return result;
    }
    
  // 解法三：二进制方法
