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
