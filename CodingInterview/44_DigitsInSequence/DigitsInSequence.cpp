int digitAiIndex(int index) {
	if (index < 0) {
		return -1;
	}
	int digits = 1;
	while (true) {
		int numbers = countOfIntegers(digits);
		if (index < numbers * digits)
			return digitAtIndex(index, digits);
		index -= digits * numbers;
		++digits;
	}

	return -1;
}

// 获得digits位的数字共有多少个
int countOfIntegers(int digits) {
	if (digits == 1) {
		return 10;
	}
	int count = (int)pow(10, digits - 1);
	return 9 * count;
}

// 获取digits位数的第index个数字
int digitAtIndex(int index, int digits) {
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index % digits; // 确定需要的是number的右数第几个数字
	for (int i = 1; i < indexFromRight; ++i) {
		number /= 10; // number/10将位数降低
	}
	return number % 10;
}

// 获得digits位的第一个数字
int beginNumber(int digits) {
	if (digits == 1) {
		return 0;
	}
	return (int)pow(10, digits - 1);
}

