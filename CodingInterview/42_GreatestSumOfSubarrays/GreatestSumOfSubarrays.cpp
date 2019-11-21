// 剑指offer解法
// 将最大的子数组和初始化为最小的负数

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty()) {
		return 0;
	}
	int nCurSum = 0;
	int nGreatestSum = 0x80000000; // 负数最小值
	for (int i = 0; i < array.size(); ++i) {
		if (nCurSum <= 0) {
			nCurSum = array[i];
		}
		else {
			nCurSum += array[i];
		}
		if (nCurSum > nGreatestSum) {
			nGreatestSum = nCurSum;
		}
	}
	return nGreatestSum;

}

// 牛客网解法
// 将最大的子数组和初始化为array[0]

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty()) {
		return 0;
	}
	int nCurSum = array[0];
	int nGreatestSum = array[0];
	for (int i = 1; i < array.size(); ++i) {
		if (nCurSum <= 0) {
			nCurSum = array[i];
		}
		else {
			nCurSum += array[i];
		}
		if (nCurSum > nGreatestSum) {
			nGreatestSum = nCurSum;
		}
	}

	return nGreatestSum;

}
