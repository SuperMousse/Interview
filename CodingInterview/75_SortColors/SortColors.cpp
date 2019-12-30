// 解法一: 对0，1，2出现的次数计数，然后覆盖重写


// 解法二: 维护首尾双指针，移动双指针进行交换
void sortColors(vector<int>& nums) {
    if(nums.empty()){
        return;
    }
    int length = nums.size();
    int left = 0;
    int right = length - 1;
    for (int i = 0; i <= right; ++i) {
        if(nums[i] == 0) {
            swap(nums[i], nums[left++]); // 换到左侧的一定是0，当前元素一定比0大
        }
        else if(nums[i] == 2) {
            swap(nums[i--], nums[right--]); // 从右侧换过来的元素可能是1，可能是2，需要重复考虑一下是否为2，要不要换到右侧
        }
        else {
            continue;
        }

    }
    return;
}

