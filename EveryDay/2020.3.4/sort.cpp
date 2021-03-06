// 计数排序, 时间复杂度O(N+K)， 空间复杂度O(N+K)
// 统计每个数字的频次, 然后依次写入新数组
vector<int> countSort(vector<int> nums) {
    if (nums.size() < 1) {
        return vector<int>();
    }
    int maxValue = nums[0];
    int minValue = nums[0];
    for(auto n : nums) {
        maxValue = n > maxValue ? n : maxValue;
        minValue = n < minValue ? n : minValue;
    }
    vector<int> count(maxValue - minValue + 1);
    vector<int> result(nums.size());
    // 计数
    for (int i = 0; i < nums.size(); ++i) {
        count[nums[i] - minValue]++;
    }
    // 填充
    int sortedIndex = 0;
    for (int i = 0; i < count.size(); ++i) {
        while(count[i] > 0) {
            result[sortedIndex++] = minValue + i;
            count[i] -= 1;
        }
    }
    return result;
}

// Minimum adjacent swaps to move maximum and minimum to corners
// Given N number of elements, find the minimum number of swaps 
// required so that the maximum element is at the beginning and the 
// minimum element is at last with the condition that only swapping 
// of adjacent elements is allowed.
// 找到左数最大的数字索引l, 右数最小的数字索引r
// If l < r: Number of swaps = l + (n-r-1)
// If l > r: Number of swaps = l + (n-r-2)
int minimumAdjacentSwaps(vector<int>& nums) {
    if (nums.size() < 1) {
        return 0;
    }
    int leftMaxIndex = 0;
    int rightMinIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
        // 大于号, 左数最大
        if (nums[i] > nums[leftMaxIndex]) {
            leftMaxIndex = i;
        }
        // 小于等于, 右数最小
        if (nums[i] <= nums[rightMinIndex]) {
            rightMinIndex = i;
        }
    }
    if (leftMaxIndex < rightMinIndex) {
        // 交换区间不重叠, max移动l次, min移动n-r-1次
        return leftMaxIndex + (nums.size() - rightMinIndex - 1);
    }
    else {
        // 交换区间重叠, min已经向右移动了一个了, 可以少移动一次
        return leftMaxIndex + (nums.size() - rightMinIndex - 2);
    }
}
