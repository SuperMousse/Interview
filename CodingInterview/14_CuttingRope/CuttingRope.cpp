// 动态规划
int cutRope(int number) {
	if (number < 2) {
		return 0;
	}
	if (number == 2) {
		return 1;
	}
	if (number == 3) {
		return 2;
	}

	int* products = new int[number + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= number; ++i) {
		max = 0;
		for (int j = 1; j <= i / 2; ++j) {
			int product = products[j] * products[i - j];
			if (max < product) {
				max = product;
			}
			products[i] = max;
		}
	}
	max = products[number];
	delete[] products;
	return max;
}


// 贪婪算法
int cutRope(int number) {
	if (number < 2) {
		return 0;
	}
	if (number == 2) {
		return 1;
	}
	if (number == 3) {
		return 2;
	}

	// 尽可能多地剪去长度为3的绳子段
	int timesOf3 = number / 3;

	// 当绳子最后剩下的长度为4的时候,不能再剪去长度为3的绳子段
	// 此时更好的方法是把绳子剪成长度为2的两段, 因为2*2 > 3*1
	if (number - timesOf3 * 3 == 1) {
		timesOf3 -= 1;
	}

	int timesOf2 = (number - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3))* (int)(pow(2, timesOf2));
}
