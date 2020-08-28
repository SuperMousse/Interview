// 最简单解法
// 若输入数字n, 有O(logN)位, 若判断每个数字的每一位是否含1, 总复杂度为O(NlogN)
int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 1) {
		return 0;
	}
	int number = 0;
	for (int i = 1; i <= n; ++i) {
		number += NumberOf1(i);
	}
	return number;
}

int NumberOf1(int n) {
	int number = 0;
	while (n) {
		if (n % 10 == 1) {
			++number;
		}
		n = n / 10;
	}
	return number;
}


// 时间复杂度O(logN)
// 每次去掉最高位进行递归, 递归次数与位数相同, 数字n有O(logN)位, 时间复杂度O(logN)
int NumberOf1Between1AndN_Solution(int n) {
	if (n < 1) {
		return 0;
	}

	string nToStr = to_string(n);
	
	return NumberOf1(nToStr, 0);
}


int NumberOf1(string& strN, int begin) {
	if (strN.empty() || strN[begin]<'0' || strN[begin]>'9' || begin == strN.size()) {
		return 0;
	}
	int first = strN[begin] - '0';
	unsigned int length = static_cast<unsigned int>(strN.substr(begin).size());

	if (length == 1 && first == 0) {
		return 0;
	}
	if (length == 1 && first > 0) {
		return 1;
	}

	// 假设strN是"21345"
	// 1~9999, 10000~19999, 20000~21345
	// numFirstDigit是数字10000~19999的第一位中的数目, 对于length位数其最高位的1只会出现10^(length-1)次
	// 如果first=1, 那么其最高位的1只会出现其后(length-1)位+1次, 如123456中的最高位1只会出现234567次
	// 这部分计算了10000~19999中最高位的1
	int numFirstDigit = 0;
	if (first > 1) {
		numFirstDigit = PowerBase10(length - 1);
	}
	else if (first == 1) {
		string substr = strN.substr(begin + 1); // begin+1到末尾
		numFirstDigit = atoi(substr.c_str()) + 1;
	}

	// numOtherDigits是01346-21345除了第一位之外的数位中1的数目
	// 1346, 1347, .., 1999, 11000, 11001, ..., 11345 (1000个第二位为1的), 11346, ..., 11999, 21000, 21345 (1000个)  
	int numberOtherDigits = first * (length - 1) * PowerBase10(length - 2);
	// numRecursive是1~1345中的数目
	int numRecursive = NumberOf1(strN, begin + 1);

	return numFirstDigit + numberOtherDigits + numRecursive;
}


// 10^n
int PowerBase10(unsigned int n) {
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
	{
		result *= 10;
	}
	return result;
}
