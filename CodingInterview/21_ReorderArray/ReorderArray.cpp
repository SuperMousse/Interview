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


// 剑指offer进阶解法，使用函数指针，可以将这个问题泛化，每次传进isEven或者其他函数的指针即可
bool isEven(int n) {
	return (n & 1) == 0;
}

void reOrderArray(vector<int>& array, bool (*func)(int)) {
	if (array.empty())
		return;
	unsigned int start = 0;
	unsigned int end = array.size() - 1;
	while (start < end) {
		while (start < end && !func(array[start]))
			++start;
		while (start < end && func(array[start]))
			--end;
		if (start < end) {
			int temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}

	}
}

// 牛客网上还要求交换后奇数与奇数，偶数与偶数的相对位置不变
void reOrderArray(vector<int>& array) {
	stable_partition(array.begin(), array.end(), isOk); // stable partition根据谓词把序列分成两个子列，并且保持原有的序列顺序
}


bool isOk(int n) {
	return ((n & 1) == 1);　//奇数返回真
}

// lamda解法
void reOrderArray(vector<int>& array) {
	stable_partition(array.begin(), array.end(), [](int n) {return ((n & 1) == 1); }); // stable partition根据谓词把序列分成两个子列，并且保持原有的序列顺序
}


/**
 * 1.要想保证原有次序，则只能顺次移动或相邻交换。
 * 2.i从左向右遍历，找到第一个偶数。
 * 3.j从i+1开始向后找，直到找到第一个奇数。
 * 4.将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
 * 5.終止條件：j向後遍歷查找失敗。
 */
void reOrderArray(vector<int>& array) {
	if (array.empty())
		return;
	unsigned int before = 0;
	unsigned int after = before + 1;
	while (before < array.size()) {
		while (before < array.size() && (array[before] % 2 != 0)) {
			++before;
		}
		after = before + 1;
		while (after < array.size() && (array[after] % 2 == 0)) {
			++after;
		}
		if (after < array.size()) {
			int temp = array[after];
			for (unsigned int i = before + 1; i <= after; ++i) {
				array[i] = array[i - 1];
			}
			array[before] = temp;
		}
		else {
			break;
		}
		
	}

}
