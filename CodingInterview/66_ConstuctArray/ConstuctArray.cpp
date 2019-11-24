// 剑指offer 解法
vector<int> multiply(const vector<int>& A) {
	vector<int> result;
	if (A.empty()) {
		return result;
	}

	int length = A.size();
	vector<int> C(length, 0);
	C[0] = 1;
	for (int i = 1; i < length; ++i) {
		C[i] = C[i - 1] * A[i - 1];
	}

	int temp = 1;
	for (int i = length - 2; i >= 0; --i) {
		temp *= A[i + 1];
		C[i] *= temp;
	}
	return C;
}


// 我自己的解法
