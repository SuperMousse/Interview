// 由于是有序数组, 所以才可以用双索引
// 左右双索引
// 和小了++left, 和大了--right
// 时间复杂度O(N)， 空间复杂度O(1)
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> result;
	if (array.empty()) {
		return result;
	}
	int left = 0;
	int right = array.size() - 1;
	int curSum = 0;
	while (left < right) {
		int curSum = array[left] + array[right];
		if (curSum == sum) {
			result.push_back(array[left]);
			result.push_back(array[right]);
			return result;
		}
		else if (curSum > sum) {
			--right;
		}
		else {
			++left;
		}
	}

	return result;
}
