int FindNumsAppearOnce(vector<int> data) {
	if (data.empty() || data.size() < 4) {
		throw runtime_error("wrong input");
	}
	int bitSum[32] = { 0 };
	for (int i = 0; i < data.size(); ++i) {
		int bitMask = 1;
		for (int j = 0; j < 32; ++j) {
			int bit = data[i] & bitMask;
			if (bit != 0) {
				++bitSum[31 - j]; // bitSum[31]存储最低位的二进制的和
			}
			bitMask = bitMask << 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; ++i) {
		result = result << 1;
		result += bitSum[i] % 3;
	}
	return result;
}
