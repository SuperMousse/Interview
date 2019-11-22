// 傻瓜解法一
// 1~n求和 - 数组元素求和
int GetMissingNumber(vector<int> data) {
	if (data.empty()) {
		return -1;
	}
	int length = data.size();
	int arraySum = 0;
	int totalSum = 0;
	for (int i = 0; i < length; ++i)
	{
		arraySum += data[i];
	}
	for (int i = 0; i < data[length - 1]; ++i) {
		totalSum += i;
	}
	return totalSum - arraySum;

}


// 二分法, 利用下标和元素是否相等
// 二分法, 利用下标和元素是否相等
int GetMissingNumber(vector<int> data) {
	if (data.empty()) {
		return -1;
	}
	int length = data.size() - 1;
	int start = 0;
	int end = length - 1;
	int middle = (start + end) >> 1;
	while (start <= end) {
		if (data[middle] == middle) {
			start = middle + 1;
		}
		else {
			if ((middle > 0 && data[middle - 1] == middle - 1)|| middle == 0) {
				return middle;
			}
			else {
				end = middle - 1;
			}
		}
		middle = (start + end) >> 1;
	}
	if (start == length) {
		return length;
	}

	return -1;

}
