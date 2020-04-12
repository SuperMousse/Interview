// 剑指offer解法: 动态规划, 循环

// f(i) 表示第i位上可以翻译的数字由多少个
// f(i) = f(i+1) + g(i, i+1) * f(i+2), 
// g(i, i+1) = 1 if (i, i+1)拼起来在10-25之间, 否则g(i, i+1) = 0

int GetTranslationCount(int number) {
	if (number < 1) {
		return 0;
	}
	string numberInString = to_string(number);
	return GetTranslationCountCount(numberInString);
}


int GetTranslationCountCount(const string& number) {
	int length = number.size();
	int* counts = new int[length];
	memset(counts, 0, sizeof(counts));
	int count = 0;
	
	for (int i = length - 1; i >= 0; --i) {
		count = 0;
		if (i < length - 1) {
			count = counts[i + 1]; // f(i+1)
		}
		else {
			count = 1; // 考虑单个字母本身
		}

		if (i < length - 1) {
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25) {
				if (i < length - 2) { 
					count += counts[i + 2]; // 至少倒数第三位开始才包括f(i+2)
				}
				else {
					count += 1; // 倒数第二位至多将最后两位的组合+1
				}
			}
		}
		counts[i] = count;
	}

	count = counts[0];
	delete[] counts;

	return count;
}



// 拓展解法: 递归， 时间复杂度O(2^n)

int GetTranslationCount(int number) {
	if (number <= 0) {
		return 0;
	}

	string numberToString = to_string(number);
	int length = numberToString.size();

	return GetTranslatonCountCore(numberToString, 0, length - 1);
}


int GetTranslatonCountCore(const string& number, int begin, int end) {
	if (number.empty() || begin < 0 || end > number.size() || begin > (end + 1)) {
		return 0;
	}

	if (begin == (end + 1))
		return 1;

	vector<int> v{ 1,2 };
	int first = 0;
	int second = 0;

	first = GetTranslatonCountCore(number, begin + 1, end); // f(n+1)
	if (number[begin] == '1' || (number[begin] == '2' && number[begin + 1] <= '5')) // f(n+2)
		second = GetTranslatonCountCore(number, begin + 2, end);

	return first + second;
	
}
