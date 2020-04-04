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
