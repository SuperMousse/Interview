// 字符串的全排列
// 剑指offer解法: 有重的全排列

// 去掉去重全排列解法中的if判断
/*****************************************************************************************/

// 牛客网AC解法: 去重的全排列
// 去重全排列解法一: 考虑使用find来查找是否已经重复
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


// 去重全排列解法二: 数字交换时与其后面非重复出现的数字进行交换, 即i, j交换时, [i, j)区间内没有等于j的数字

void PermutationCore(string str, vector<string>& result, int begin) {
	if (begin == str.size() - 1) { 		// begin指向str最后一个元素
		result.push_back(str);
	}
	else {
		// 为了实现去重全排列, 检查[i,j)区间内是否含有j, 不含有j时才进行交换
		for (int i = begin; i < str.size(); ++i) {
			if (IsSwap(str, begin, i)) {
				swap(str[i], str[begin]);
				PermutationCore(str, result, begin + 1);
				swap(str[i], str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
			}

		}
	}
}

bool IsSwap(string str, int begin, int end) {
	for (; begin < end; ++begin)
	{
		if (str[begin] == str[end])
			return false;
	}
	return true;
}

/*****************************************************************************************/


// 字符串的组合

// 解法一
// 位计算法
// 若字符串长度为n, 则所有组合之和为C(1,n)+C(2,n)+...+C(n,n)=2^(n)-1;
vector<string> combination(string str) {
	vector<string> result;
	if (str.empty()) {
		return result;
	}
	int length = str.size();
	int n = 1 << length; // 2^n
	for (int i = 1; i < n; ++i)    //从 1 循环到 2^len -1
	{
		string s;
		for (int j = 0; j < length; ++j)
		{
			int temp = i;
			if (temp & (1 << j))   //对应位上为1，则输出对应的字符
			{
				s += str[j];
			}
		}
		result.push_back(s);

	}

	sort(result.begin(), result.end());
	return result;
}


// 解法二
vector<string> Combination(string str) {
    vector<string> result;
    if (str.empty()) {
        return result;
    }

    string substring;
    CombinationCore(str, result, substring, str.size(), 0);

    sort(result.begin(), result.end());
    
    
    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return result;
}

void CombinationCore(string str, vector<string>& result, string substring,
                     int length, int begin) {
    result.push_back(substring);
    
    for (int i = begin; i < length; ++i) { // 从前向后依次选取
        substring.push_back(str[i]);
        CombinationCore(str, result, substring, length, i + 1);
        substring.pop_back();
    }
    return;
}
