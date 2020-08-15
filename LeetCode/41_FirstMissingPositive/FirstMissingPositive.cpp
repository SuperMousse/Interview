// 给定未排序数组, 找到第一个缺失的正整数
// Input: [1,2,0]
// Output: 3
// Input: [3,4,-1,1]
// Output: 2
// Input: [7,8,9,11,12]
// Output: 1

// 分析:
// 把数字i放在数组中的i-1的位置上, 即数字5放在nums[4]上,
// idx: 0, 1, 2, 3, ...
// val: 1, 2, 3, 4, ...
// 最后重新扫描的时候, 第一个不满足 数值=索引+1 的位置就是第一个缺失的正整数索引, 返回索引+1
// 复杂度O(3n), 第一个循环O(2n), 第二个O(n)

int firstMissingPositive(vector<int>& nums) {
    if (nums.empty()) {
        return 1;
    }
    int length = nums.size();
    for (int i = 0; i < length; ++i) {
        // 这一步的while循环至多执行两次, 因为执行一次就表示把一个数字放在了正确的位置上
        // 虽然可能会换过来一个数字导致while继续执行, 但是对于全局的所有数字来说, 每个数字
        // 最多执行了a.被换到某个位置上 b.被正确放置, 所以这个大的for循环复杂度为O(2n)
        // 判断nums[i]=5和nums[4]上的数字是否相等, 即5是否放在nums[4]上
        while (nums[i] > 0 && nums[i] <= length && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < length; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return length + 1;
}
