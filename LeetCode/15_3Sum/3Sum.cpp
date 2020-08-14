 // 时间复杂度O(N^2), 空间复杂度O(1)
 // Input: [-1,0,1,2,-1,-4]
 // Output: [[-1, -1, 2], [-1, 0, 1]]

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> > result;
	if (nums.size() < 3) {
		return result;
	}
	sort(nums.begin(), nums.end());
	int length = nums.size();
	for (int i = 0; i < length - 2; ++i)
	{
		// 递增数组中triplet第一个元素大于0, 那么triplet之和不可能为0
		if (nums[i] > 0) {
			break;
		}
		// i=0无论何时都作为triplet的第一个元素; i>0的元素只使用第一个不重复的元素作为triplet的第一个元素
		// 如 -1, -1, 2, 3只使用第二个-1, 因为两个-1会产生相同的triplet
		if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
			int left = i + 1;
			int right = length - 1;
			int sum = 0 - nums[i];
			// 双指针two sum
			while (left < right) {
				if (nums[left] + nums[right] == sum) {
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					// skip duplicate number
					while (left < right && nums[left] == nums[left + 1]) {
						++left;
					}
					// skip duplicate number
					while (left < right && nums[right] == nums[right - 1]) {
						--right;
					}
					++left;
					--right;
				}
				else if (nums[left] + nums[right] < sum) {
					++left;
				}
				else {
					--right;
				}
			}
		}
	}
	return result;
}
