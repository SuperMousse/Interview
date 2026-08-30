// 有序数组中寻找target，target存在多个，寻找第一个和最后一个，返回索引
class Solution {
public:
    int binary_search_end(vector<int>&nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int result = -1;
        while(begin <= end) {
            int half = begin + (end - begin) / 2;
            if (nums[half] == target) {
                result = half;
            }
            // target大于等于Half，驱动向右搜索
            if (target >= nums[half]) {
                begin = half + 1;
            } else {
                end = half - 1; 
            }
        }
        return result;
    }
    int binary_search_first(vector<int>&nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int result = -1;
        while(begin <= end) {
            int half = begin + (end - begin) / 2;
            // 相等时记录下来，继续搜索
            if (nums[half] == target) {
                result = half;
            }
            // target小于等于Half，驱动向左搜索
            if (target <= nums[half]) {
                end = half - 1;
            } else {
                begin = half + 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            return vector<int>{-1, -1};
        }
        int begin = binary_search_first(nums, target);
        int end = binary_search_end(nums, target);
        if (begin == -1 || end == -1) {
            return vector<int>{-1, -1};
        }
        return vector<int>{begin, end};
    }
};
