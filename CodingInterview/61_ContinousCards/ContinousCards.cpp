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
// 顺子满足的条件：max-min<5;
//				除0外其他的数字都不能重复
//				传入的数组放5个元素
bool IsContinuous(vector<int> numbers) {
	if (numbers.empty()) return 0;
	int count[14] = { 0 };//记录每个元素出现的次数;以numbers中的元素作为下标(最大K,对应13)
	int len = numbers.size();
	int max = -1;
	int min = 14;

	for (int i = 0; i < len; ++i)
	{
		++count[numbers[i]];
		if (numbers[i] == 0) {
			continue;
		}

		if (count[numbers[i]] > 1) {
			return false;
		}

		// 统计除了0以外的最大值,最小值
		if (numbers[i] > max) {
			max = numbers[i];
		}

		if (numbers[i] < min) {
			min = numbers[i];
		}

	}

	if (max - min < 5) {
		return true;
	}

	return false;

}
