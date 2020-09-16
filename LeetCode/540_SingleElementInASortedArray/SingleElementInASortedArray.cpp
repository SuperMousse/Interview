// 有序数组中一个数字出现了一次, 其余数字都出现了两次, 返回这个数字
// index: 0 1 2 3 4 5 6 7 8
// nums:  1 1 2 3 3 4 4 8 8
// left = 0, right = 7, middle = 3 => middle = 2, nums[2] != nums[3], single number在右侧

int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        // 让middle落在一对数字中的第一个, 要求索引是偶数, 如果是奇数, middle-=1
        int middle = left + (right - left) / 2;
        if (middle % 2 == 1) {
            --middle;
        }
        if (nums[middle] != nums[middle+1]) {
            right = middle;
        }
        else {
            left = middle + 2;
        }
    }
    return nums[left];
}
