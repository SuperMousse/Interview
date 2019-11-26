// 解法一: 直接解法, 遍历每一数字
int GetUglyNumber_Solution(int index) {
	if (index < 1) {
		return 0;
	}
	int number = 0;
	int uglyFound = 0;
	while (uglyFound <= index) {
		++number;
		if (IsUgly(number)) {
			++uglyFound;
		}
	}

	return number;
}

bool IsUgly(int number) {
	while (number % 2 == 0) {
		number /= 2;
	}
	while (number % 3 == 0) {
		number /= 3;
	}
	while (number % 5 == 0) {
		number /= 5;
	}
	return (number == 1) ? true : false;
}


// 解法二: 
