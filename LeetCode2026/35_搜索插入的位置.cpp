// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 输入: nums = [1,3,5,6], target = 5
// 输出: 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 转化为找到数组中第一个大于等于target的数字下标，target就插入在这个数字前面
        // 或者找数组中最后一个小于target的数字下标，target插入在这个数字后面
        int begin = 0;
        int end = nums.size() - 1;
        int half = 0;
        int result = nums.size();  // 如果不存在大于等于target的数字，target插入在nums.size()位置上
        while(begin <= end) {
            half = (begin + end) / 2;
            if (target <= nums[half]) {
                result = half;
                end = half - 1;
            } else {
                begin = half + 1;
            }
        }   
        return result;
    }
};
