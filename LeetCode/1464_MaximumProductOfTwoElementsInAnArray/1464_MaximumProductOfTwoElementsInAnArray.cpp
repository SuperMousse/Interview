
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
