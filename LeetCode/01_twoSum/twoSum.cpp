// 时间复杂度O(N), 空间复杂度O(N)

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	if (nums.empty()) {
		return result;
	}
	unordered_map<int, int> numToIndex;
	for (int i = 0; i < nums.size(); ++i)
	{
		int complement = target - nums[i];
		if (numToIndex.find(complement) != numToIndex.end()) {
			result.push_back(numToIndex[complement]);
			result.push_back(i);
		}
		numToIndex[nums[i]] = i;
	}
	return result;;
}
