
int GetNumberSameAsIndex(vector<int> numbers) {
	if (numbers.empty()) {
		return -1;
	}
	int length = numbers.size();
	int start = 0;
	int end = numbers.size() - 1;
	int middle = (start + end) >> 2;
	while (start <= end) {
		if (numbers[middle] == middle) {
			return middle;
		}
		else if (numbers[middle] > middle) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}

	return -1;
}
