// 解法一: 直接解法, 遍历每一数字
// 该解法用时几十秒, 牛客网无法正常AC
int GetUglyNumber_Solution(int index) {
	if (index < 1) {
		return 0;
	}
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index) {
		++number;
		if (IsUgly(number)) {
			++uglyFound;
			cout << uglyFound << ":" << number << endl;
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


// 解法二: 剑指offer解法
int GetUglyNumber_Solution(int index) {
	if (index < 1) {
		return 0;
	}
	vector<int> result(index, 0);
	result[0] = 1;
	int nextUglyIndex = 1;
	int positionOf2 = 0, positionOf3 = 0, positionOf5 = 0;

	while (nextUglyIndex < index) {
		int min = Min(result[positionOf2] * 2, result[positionOf3] * 3, result[positionOf5] * 5);
		result[nextUglyIndex] = min;

		while (result[positionOf2] * 2 <= result[nextUglyIndex]) {
			++positionOf2;
		}
		while (result[positionOf3] * 3 <= result[nextUglyIndex]) {
			++positionOf3;
		}
		while (result[positionOf5] * 5 <= result[nextUglyIndex]) {
			++positionOf5;
		}
		++nextUglyIndex;
	}

	return result[index - 1];
}

int Min(int number1, int number2, int number3) {
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}


// 解法三: 牛客网解法, 与剑指offer解法的区别就在于对于position的递增策略上使用了if or while
int GetUglyNumber_Solution(int index) {
	if (index < 1) {
		return 0;
	}
	vector<int> result(index, 0);
	result[0] = 1;
	int UglyIndex = 1;
	int positionOf2 = 0, positionOf3 = 0, positionOf5 = 0;
	for (UglyIndex = 1; UglyIndex < index; ++UglyIndex) {
		result[UglyIndex] = min(result[positionOf2] * 2, min(result[positionOf3] * 3, result[positionOf5] * 5));
		if (result[UglyIndex] == result[positionOf2] * 2) {
			++positionOf2;
		}
		if (result[UglyIndex] == result[positionOf3] * 3) {
			++positionOf3;
		}
		if (result[UglyIndex] == result[positionOf5] * 5) {
			++positionOf5;
		}
		
	}

	return result[index - 1];
}
