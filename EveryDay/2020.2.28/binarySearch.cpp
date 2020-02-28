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
// 数组一直递增, 数组的峰值出现在末尾, 因为n+1被认为是-inf
// 数组如果中间有peak, 那么就会产生在递增序列的最后一个元素上
// 因此对于检测到递增时, 只需要向右检测
// 否则向左检测
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

// 找到最接近的k个元素
// 方法一: 二分查找搜单个数值, 然后左右扩张

// 方法二: 区间二分查找
