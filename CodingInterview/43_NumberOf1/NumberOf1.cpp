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


// 
