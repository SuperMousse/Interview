// 直观解法, 时间复杂度O(N)
int GetNumberOfK(vector<int> data, int k) {
	if (data.empty()) {
		return 0;
	}
	int numbers = 0;
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] == k)
			++numbers;
	}
	return numbers;
}
