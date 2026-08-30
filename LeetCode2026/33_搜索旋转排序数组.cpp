class Solution {
public:
    // 数组包含有序区间，无序区间，根据begin <= half，half <= end，就能区分2个区间
    // 如果[begin, mid]是有序的，且target在这个区间内，那就搜[begin，mid]，否则搜另外区间
    // 如果[mid，end]是有序的，且target在这个区间，那就搜[mid，end]，否则搜另外区间
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end) {
            int half = begin + (end - begin) / 2;
            if (nums[half] == target) {
                return half;
            }
            // 左区间有序
            if (nums[begin] <= nums[half]) {
                if (target >= nums[begin] && target <= nums[half]) {
                    end = half - 1;
                } else {
                    begin = half + 1;
                }
            } 
            // 右区间有序，和上面理论互斥
            if (nums[half] <= nums[end]) {
                if (target >= nums[half] && target <= nums[end]) {
                    begin = half +1;
                } else {
                    end = half -1;
                }
            }
            
        }
        return -1;
    }
};
