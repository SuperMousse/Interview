
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

// 非递归快排
void quickSort(vector<int>& nums, int start, int end) {
    stack<int> st;
    st.push(start);
    st.push(end);
    while (!st.empty()) {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        if (left >= right) {
            continue;
        }
        int middle = partition(nums, start, end);
        st.push(left);
        st.push(middle - 1);

        st.push(middle + 1);
        st.push(right);
    }
    return;
}




// 归并排序, 空间复杂度O(N)
// 注意, 首先要把数组分成两部分, 然后再把两部分当做有序数组来进行合并
void merge(vector<int>& nums, int start, int middle, int end, vector<int>& temp) {
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

// 归并merge, 空间复杂度O(1)
void merge(vector<int>& arr, int start, int middle, int end)
{
    int i = start; // 左序列指针
    int j = middle + 1; // 右序列指针
    int k = 0;
    int key = 0;
    while (i < j && j <= end)  //当i等于j或者j到达末尾时终止
    {
        if (arr[i] > arr[j])
        {
            k = j;
            key = arr[j];
            // 发现j上的数字比较小, 所有数字向后移动, 直到j可以放入为止
            while (k > i && arr[k - 1] > key)
            {
                arr[k] = arr[k - 1];
                --k;
            }
            arr[k] = key;
            ++j;
        }
        ++i;
    }
}




// divide and conquer
void mergeSort(vector<int>& nums, int start, int end, vector<int>& temp) {
    if (!nums.empty() && start < end) {
        int middle = (start + end) / 2;
        mergeSort(nums, start, middle, temp);
        mergeSort(nums, middle + 1, end, temp);
        merge(nums, start, middle, end, temp);
    }
    return;
}



// 基数排序
int maxbit(vector<int> nums) // 求数据的最大位数
{
    int maxVal = nums[0]; // 最大数字
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (auto n : nums) {
        maxVal = maxVal > n ? maxVal : n;
    }
    int maxbit = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        ++maxbit;
    }
    return maxbit;
}

void radixsort(vector<int>& nums) //基数排序
{
    if (nums.empty()) {
        return;
    }
    int length = nums.size();
    int maxDigit = maxbit(nums);
    vector<int> temp(length, 0);
    vector<int> count(10, 0); // 计数器
    int radix = 1;
    for(int i = 0; i < maxDigit; i++) //进行d次排序
       {
           for(int j = 0; j < 10; ++j)
               count[j] = 0; //每次分配前清空计数器
           for(int j = 0; j < length; ++j)
           {
               int k = (nums[j] / radix) % 10; //统计每个桶中的记录数
               ++count[k];
           }
           for(int j = 1; j < 10; ++j) {
               count[j] = count[j - 1] + count[j]; //将temp中的位置依次分配给每个桶
           }
           for(int j = length - 1; j >= 0; --j) //将所有桶中记录依次收集到tmp中
           {
               int k = (nums[j] / radix) % 10;
               temp[count[k] - 1] = nums[j];
               --count[k];
           }
           for(int j = 0; j < length; ++j) { //将临时数组的内容复制到data中
               nums[j] = temp[j];
           }
           radix = radix * 10;
       }
    
    return;
}
