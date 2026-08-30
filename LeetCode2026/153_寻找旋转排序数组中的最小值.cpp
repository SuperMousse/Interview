class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return INT_MAX;
        }
        int begin = 0;
        int end = nums.size() - 1;
        int minNum = INT_MAX;
        while(begin <= end) {
            int half = begin + (end - begin) / 2;
            // 左区间有序
            if (nums[begin] <= nums[half]) {
                minNum = nums[begin] < minNum ? nums[begin] : minNum;
                begin = half + 1;
            } else {
                // 右区间有序
                if (nums[half] <= nums[end]) {
                    minNum = nums[half] < minNum ? nums[half] : minNum;
                    end = half - 1;
                }
            }
        }
        return minNum;
    }
};
