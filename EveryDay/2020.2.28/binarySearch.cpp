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
// 时间复杂度: O(log(N-K) + K)
// 目标数组: arr[i] ~ arr[i + k -1]
// 搜索目标为i, 因此i的范围为0 ~ n-k, n-k是为了使用后k个元素的情况
// 对于middle-1, middle, ..., middle+k-1, middle+k
// 如果x - arr[middle] > arr[middle + k] - x,说明数组偏左, 需要往右一点
// 0, 1, 2, 3,          4,       5,  6
// middle, ... middle+k-1, middle+k
// 若x为3, 那么3-0>5-3, 说明目标值左侧的数字多于右侧的数字, 需要向右
// left, right, middle最后会收敛于i, 只不过middle后面还带着一个区间

// 二分查找边界条件总结:
// 如果想要使得目标尽可能靠左: 条件非常明确的时候才把左边界右移(+1), 否则右边界缓慢左移
// 如果想要使得目标尽可能靠右: 条件非常明确的时候把右边界左移(-1), 否则左边界缓慢右移
// 本题希望区间靠左, 选择第一种
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    if (arr.empty() || k < 1) {
        return vector<int>();
    }
    int left = 0;
    int right = arr.size() - k;
    while (left < right) {
        int middle = (left + right) / 2;
        if (x - arr[middle] > arr[middle + k] - x) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}
