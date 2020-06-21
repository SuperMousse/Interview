// 两次二分查找
// 先搜左侧, 再搜右侧, 注意二分搜索时候的middle ,start, end有无+1
vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.empty()) {
            return result;
        }
        int start = 0;
        int end = nums.size() - 1;
        // search left
        while(start < end){
            int middle = (start + end) / 2;
            if(nums[middle] < target){
                start = middle + 1;
            }
            else{
                end = middle;
            }
        }
        if(nums[start] != target){
            return result;
        }
        else{
            result[0] = start;
        }
        // search right
        end = nums.size() - 1;
        while(start < end) {
            int middle = (start + end) / 2 + 1; // make middle biased to right, for midddle - 1
            if(nums[middle] > target) {
                end = middle - 1;
            }
            else{
                start = middle;
            }
        }
        result[1] = end;
        cout << start << endl;
        return result;

    }
