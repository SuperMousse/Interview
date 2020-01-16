// 解法一, 与寻找中位数方法一样，寻找k-1位数,然后k-1位数之前的都是比其小的数字
// 时间复杂度O(N), 空间复杂度O(1)
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
       vector<int> result;
        int length = input.size();
        if (input.empty() || k <= 0 || k > length) {
            return result;
        }
	int length = input.size();
	int start = 0;
	int end = length - 1;
	int index = Partition(input, start, end);
	cout << index << endl;

	return result;
	while (index != (k - 1)) {
		if (index > (k - 1)) {
			end = index - 1;
			index = Partition(input, start, end);
		}
		else {
			start = index + 1;
			index = Partition(input, start, end);
		}
	}

	for (int i = 0; i < k; ++i) {
		result.push_back(input[i]);
	}
	sort(result.begin(), result.end());

	for (auto i : input) {
		cout << i << " ";
	}

	return result;

}


int Partition(vector<int>& input, int start, int end) {
	if (input.empty()) {
		return 0;
	}
	int base = start;
	int left = start;
	int right = end;
	while (true) {
		while (left<right && input[right]>input[base]) {
			--right;
		}
		while (left < right && input[left] <= input[base]) {
			++left;
		}
		if (left == right)
			break;
		int temp = input[left];
		input[left] = input[right];
		input[right] = temp;
	}

	int temp = input[base];
	input[base] = input[left];
	input[left] = temp;

	return left;
}


// 解法二
// 维护一个k大小的容器,循环遍历数组，确定是否插入到容器中
// set/multiset(底层红黑树)可以在O(logK)实现查找、删除、插入
// 共N个节点,总时间复杂度O(NlogK)
// 适用于海量数据
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	int length = input.size();
	if (input.empty() || k <= 0 || k > length) {
		return result;
	}
	multiset<int, greater<int> > KSet; // greater表示内置类型从小到大排序
	multiset<int, greater<int> >::iterator KSetIterator; // erase
	for (int i = 0; i < length; ++i) {
		if (KSet.size() < k) {
			KSet.insert(input[i]);
		}
		else {
			KSetIterator = KSet.begin();
			if (input[i] < *KSetIterator) {
				// 不能使用earse(value)的原因就是erase(value)会删除掉所有对应的value, 
				// 但是iter的erase可以只是删除掉指向的那个
				KSet.erase(KSetIterator); 
				KSet.insert(input[i]);
			}
		}
	}
	result = vector<int>(KSet.begin(), KSet.end());

	return result;

}
