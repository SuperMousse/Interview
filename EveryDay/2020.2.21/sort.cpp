// 排序
// 快速排序, 适用于链表写法
int partition(vector<int>& nums, int begin, int end) {
    if (begin == end) {
        return begin;
    }
    int base = begin;
    int slow = begin;
    int fast = slow + 1;
    while (fast <= end) {
        if (nums[fast] < nums[base]) {
            ++slow;
            swap(nums[slow], nums[fast]);
        }
        ++fast;
    }
    swap(nums[base], nums[slow]);
    return slow;
}


void quickSort(vector<int>& nums, int start, int end) {
    if(!nums.empty() && start <= end) {
        int index = partition(nums, start, end);
        quickSort(nums, start, index - 1);
        quickSort(nums, index + 1, end);
    }
    return nums;

}




// 归并排序
