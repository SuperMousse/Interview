
//  基数排序：根据键值的每位数字来分配桶, 先按照各位数字分桶, 再按照十位数字分桶, 依次递推
//  计数排序：每个桶只存储单一键值
//  桶排序：每个桶存储一定范围的数值


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
// 注意, 首先要把数组分成两部分, 然后再把两部分当做有序数组来进行合并
void merge(vector<int>& nums, int start, int middle, int end) {
    vector<int> temp(end - start + 1, -1); // 临时存储
    int i = start; // 左序列指针
    int j = middle + 1; // 右序列指针
    int t = 0; // 临时数组指针
    while (i <= middle && j <= end) {
        if(nums[i] <= nums[j]) {
            temp[t++] = nums[i++];
        }
        else{
            temp[t++] = nums[j++];
        }
    }
    // 拷贝左侧数组剩余元素
    while (i <= middle) {
        temp[t++] = nums[i++];
    }
    while (j <= end) {
        temp[t++] = nums[j++];
    }
    // 拷贝temp到nums范围内
    t = 0;
    while (start <= end) {
        nums[start++] = temp[t++];
    }
}

// divide and conquer
void mergeSort(vector<int>& nums, int start, int end) {
    if (!nums.empty() && start < end) {
        int middle = (start + end) / 2;
        mergeSort(nums, start, middle);
        mergeSort(nums, middle + 1, end);
        merge(nums, start, middle, end);
    }
    return;
}



// 基数排序
