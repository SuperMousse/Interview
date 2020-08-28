// 找到三数之和离target最近的, 返回这个和

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int length = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < length - 2; ++i)
    {
        // i=0无论何时都作为triplet的第一个元素; i>0的元素只使用第一个不重复的元素作为triplet的第一个元素
        // 如 -1, -1, 2, 3只使用第二个-1, 因为两个-1会产生相同的triplet
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int left = i + 1;
            int right = length - 1;
            // 双指针two sum
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < target) {
                    // skip duplicate number
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    ++left;
                }
                else {
                    // skip duplicate number
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    --right;
                }
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
            }
        }
    }
    return closest;
}
