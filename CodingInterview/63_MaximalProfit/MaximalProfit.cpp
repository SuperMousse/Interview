int MaxDiff(vector<int> numbers) {
	if (numbers.empty()) {
		return 0;
	}
	int min = numbers[0];
	int maxDiff = numbers[1] - min;
	int length = numbers.size();

	for (int i = 2; i < length; ++i)
	{
		if (numbers[i - 1] < min) {
			min = numbers[i - 1];
		}
		int currentDiff = numbers[i] - min;
		if (currentDiff > maxDiff) {
			maxDiff = currentDiff;
		}
	}

	return maxDiff;
}
