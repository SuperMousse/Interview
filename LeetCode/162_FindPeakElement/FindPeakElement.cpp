int findPeakElement(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int length = nums.size();
    int left = 0;
    int right = length - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        int middleRight = middle + 1;
        // middle < middleRight说明峰值在middleRight及其右侧
        // 否则, 峰值在middle及其左侧
        if (nums[middle] < nums[middleRight]) {
            left = middleRight;
        }
        else {
            right = middle;
        }
    }
    return left;
}
