// 剑指offer答案
void reOrderArray(vector<int>& array) {
	if (array.empty())
		return;
	unsigned int start = 0;
	unsigned int end = array.size() - 1;
	while (start < end) {
		while (start < end && (array[start] % 2) != 0)
			++start;
		while (start < end && (array[end] % 2) == 0)
			--end;
		if (start < end) {
			int temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}

	}
}

// 牛客网上还要求交换后奇数与奇数，偶数与偶数的相对位置不变
