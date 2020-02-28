// 找峰值
// 解法一: 线性扫描
// 该解法要求一定存在peak
int findPeakElement(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int length = nums.size();
    for (int i = 1; i < length; ++i) {
        // 如果没有return，说明nums[i] >= nums[i-1]
        // 那么如果nums[i+1] < nums[i], nums[i]就是peak
        if (nums[i] < nums[i - 1]) {
            return i - 1;
        }
    }
    // 因为假设一定存在peak, 如果没有找到peak, 说明length=1
    return length - 1;
}

// 解法二: 二分查找

//
