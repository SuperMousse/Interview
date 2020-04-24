vector<int> plusOne(vector<int>& digits) {
	if (digits.empty()) {
		return digits;
	}
	int len = digits.size();
	int carry = 1;
	for (int i = len - 1; i >= 0; --i) {
		int carry_temp = (digits[i] + carry) / 10;
		int digit_temp = (digits[i] + carry) % 10;
		carry = carry_temp;
		digits[i] = digit_temp;
	}
	if (carry != 0) {
		vector<int> res;
		res.push_back(carry);
		for (auto i : digits) {
			res.push_back(i);
		}
		return res;
	}

	return digits;
}
