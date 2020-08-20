// 给定数组, 选择两个不同的索引 i, j, 返回(nums[i]-1)*(nums[j]-1)的最大值
// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

// Input: nums = [1,5,4,5]
// Output: 16
// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

int maxProduct(vector<int>& nums) {
    if (nums.size() < 2) {
        return -1;
    }
    int largest = nums[0] < nums[1] ? nums[1] : nums[0];
    int secondLargest = nums[0] < nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secondLargest && nums[i] <= largest) {
            secondLargest = nums[i];
        }
    }
    return (largest - 1) * (secondLargest - 1);
}
