int  NumberOf1(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			++count;
		}
		flag = flag << 1;
	}
	return count;
}
