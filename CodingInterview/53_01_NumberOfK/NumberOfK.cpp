// 直观解法一, 顺序扫描, 时间复杂度O(N)
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


// 解法二, 二分查找+左右扫描, 由于顺序扫描时间复杂度为时间复杂度O(N), 则该算法最差时间复杂度为O(N)


// 解法三, 二分查找first value+二分查找last value, 时间复杂度O(logN)
