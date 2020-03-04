// 有序数组中去除重复数字, 并且返回无重复数组长度
int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }
    int count = 0;
    int length = nums.size();
    for (int i = 1; i < length; ++i) {
        if (nums[i] == nums[i-1]) {
            ++count;
        }
        else {
            nums[i-count] = nums[i];
        }
    }
    return length - count;
}
