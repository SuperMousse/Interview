vector<vector<int> > FindNumbersWithSum(int sum) {
	vector<vector<int> > result;
	if (sum < 3) {
		return result;
	}
	int left = 1;
	int right = 2;
	int middle = (1 + sum) / 2;
	int curSum = left + right;
	while (left < middle) {
		if (curSum == sum) {
			vector<int> temp;
			for (int i = left; i <= right; ++i) {
				temp.push_back(i);
			}
			result.push_back(temp);
		}
		// curSum大了, 一直left向右移动
		while (curSum > sum && left < middle) {
			curSum -= left;
			++left;
			if (curSum == sum) {
				vector<int> temp;
				for (int i = left; i <= right; ++i) {
					temp.push_back(i);
				}
				result.push_back(temp);
			}
		}
		// curSum小了, ++right
		++right;
		curSum += right;
	}

	return result;

}
