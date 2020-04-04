Given a non-empty integer array, find the minimum number of moves required to 
make all array elements equal, where a move is incrementing a selected element 
by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]


// 因为只能选择一个数字+1, 或-1, 最快速相等的方法是使得所有数字都变成数组的中位数(奇数时取中间, 偶数时取中间两个中靠后的一个)
// 首尾结对两个数字的绝对差值确定了之后, 无论这两个数字相对变成什么数字都不会改变变换的次数
// 前面数字1, 后面数字20, 中位数10, 20 - 1 = 19, 1变换9次, 20变换10次
// 前面数字1, 后面数字20, 中位数12, 20 - 1 = 19, 1变换11次, 20变换8次
// 因此数字结对的差值和就是最终变换的次数

int minMoves2(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int left = 0;
    int right = nums.size() - 1;
    int result = 0;
    sort(nums.begin(), nums.end(), less<int>());
    while (left < right) {
        result += nums[right] - nums[left];
        ++left;
        --right;
    }
    return result;
}
