void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
	if (data.empty() || data.size() < 2) {
		return;
	}
	int resultExclusiveOR = 0;
	for (int i = 0; i < data.size(); ++i)
	{
		resultExclusiveOR ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < data.size(); ++i) {
		if (IsBit1(data[i], indexOf1)) {
			*num1 ^= data[i];
		}
		else {
			*num2 ^= data[i];
		}
	}
}


unsigned int FindFirstBitIs1(int num) {
	int indexBit = 0;
	while (((num & 0x1) == 0) && (indexBit < (8 * sizeof(int)))) {
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit) {
	num = num >> indexBit;
	return (num & 0x1);
}
