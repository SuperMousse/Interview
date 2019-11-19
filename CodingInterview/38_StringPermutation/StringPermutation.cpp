vector<string> Permutation(string str) {
	vector<string> result;
	if (str.empty()) {
		return result;
	}
	PermutationCore(str, result, 0);

	sort(result.begin(), result.end()); // 得到的result并非字典排序, 牛客网要求字典序

	return result;
}

void PermutationCore(string str, vector<string>& result, int begin) {
	if (begin == str.size() - 1) { 		// begin指向str最后一个元素
		if (find(result.begin(), result.end(), str) == result.end()) {
			// 如果result中不存在str,才添加，避免重复添加
			result.push_back(str);
		}
	}
	else {
		//第一次循环i与begin相等，相当于第一个位置自身交换，关键在于之后的循环，
		// 之后i != begin，则会交换两个不同位置上的字符，直到begin==str.size()-1，进行输出；
		for (int i = begin; i < str.size(); ++i) {
			swap(str[i], str[begin]);
			PermutationCore(str, result, begin + 1);
			swap(str[i], str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
		}
	}
}

void swap(char& first, char& second)
{
	char temp = first;
	first = second;
	second = temp;
}
