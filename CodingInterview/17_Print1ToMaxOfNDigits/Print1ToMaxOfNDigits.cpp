// 解法一
bool Increment(char* number);
void PrintNumber(char* number);

void Print1ToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number)) {
		PrintNumber(number);
	}
	delete[] number;
	return;
}

bool Increment(char* number) {
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; --i) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1) {
			++nSum;
		}
		if (nSum >= 10) {
			if (i == 0) {
				isOverflow = true;
			}
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else {
			number[i] = '0' + nSum;
			break;
		}

	}
	return isOverflow;
}

void PrintNumber(char* number) {
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i) {
		if (isBeginning0 && number[i] != '0') {
			isBeginning0 = false;
		}
		if (!isBeginning0) {
			cout << number[i] << " ";
		}
	}

	cout << "\t";
}



// 解法二
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);
void PrintNumber(char* number);

void Print1ToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; ++i) {
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete[] number;
	return;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void PrintNumber(char* number) {
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i) {
		if (isBeginning0 && number[i] != '0') {
			isBeginning0 = false;
		}
		if (!isBeginning0) {
			cout << number[i] << " ";
		}
	}

	cout << "\t";
}


// 17.1 
/*
前面的代码中，我们都是用一个char型字符表示十进制数字的一位。
8个bit的char型字符最多能表示256个字符，而十进制数字只有0-9的10个数字。
因此用char型字符串来表示十进制的数字并没有充分利用内存，有一些浪费。
有没有更高效的方式来表示大数
*/





// 17.2 
/*
)定义一个函数，在该函数中可以实现任意两个整数的加法。由于没有限定输入
两个数的大小范围，我们也要把它当做大数问题来处理。在前面的代码的第一个
思路中，实现了在字符串表示的数字上加1的功能，我们可以参考这个思路实现
两个数字相加功能，另外还有一个需要注意的问题：如果输入的数字中有负数，
我们应该怎么处理？
*/
