// 剑指offer解法
bool IsContinuous(vector<int> numbers) {
	if (numbers.empty()) {
		return false;
	}

	sort(numbers.begin(), numbers.end(), [](const int& a, const int& b)->bool {return a < b; });

	int numberOfZero = 0;
	int numberOfGap = 0;
	int length = numbers.size();

	// 统计数组中0的个数
	for (int i = 0; i < length && numbers[i] == 0; ++i) {
		++numberOfZero;
	}

	// 统计数组中间隔的数目
	int min = numberOfZero; // 已经排序过,所以从第一个非零元素开始
	int max = min + 1;
	while (max < length) {
		// 两个数相等, 有对子, 不可能是顺子
		if (numbers[min] == numbers[max]) {
			return false;
		}
		numberOfGap += numbers[max] - numbers[min] - 1;
		min = max;
		++max;
	}

	return (numberOfGap > numberOfZero) ? false : true;

}


// 牛客网解法
