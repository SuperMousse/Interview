// 本题在输入data非常长的时候有可能会超出int的限制, 因为%(2^10+7)
// 1000000007是最小的十位质数,模1000000007,可以保证值永远在int的范围内
/*
1.(a + b) % c = ( ( a % c ) + ( b % c ) ) % c
2.(a * b) % c = ( ( a % c ) * ( b % c ) ) % c
3.(a - b) % c = ( ( a % c ) - ( b % c ) ) % c
4.(a / b) % c = ( ( a % c ) / ( b % c ) ) % c(不成立)
*/


int InversePairs(vector<int> data) {
	if (data.empty()) {
		return 0;
	}

	int length = data.size();
	vector<int> copy(data);

	long long count = InversePairsCore(data, copy, 0, length - 1); // 逆序对数目在data长度很长时有可能超出最大int的限制
	                                                         // 1000000007是最小的十位质数,模1000000007,可以保证值永远在int的范围内

	return count % 1000000007;
}

long long InversePairsCore(vector<int>& data, vector<int>& copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];  // 这句话似乎没啥用
		return 0;
	}

	int length = (end - start) / 2;

	long long left = InversePairsCore(copy, data, start, start + length);  // 二分O(logN), 递归时copy和data进行交替嵌套, 因为copy和data是交替局部有序的
	                                                                       // 当最底层时, data=copy, 然后其中的一个变为了局部有序的, 返回上一层之后, 以局部有序
	                                                                       // 的那一个当作模版, 对另外一个进行覆盖
	long long right = InversePairsCore(copy, data, start + length + 1, end); // 获得左右二分的逆序对数目, 然后与当前的逆序对数进行求和

	// i初始化为前半段最后一个数字的下标
	int i = start + length;
	// j初始化为后半段最后一个数字的下标
	int j = end;
	int indexCopy = end;
	long long count = 0;
	while (i >= start && j >= start + length + 1) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length; // j-(start+length), 逆序对实际上考察的是j是后半部分中的第几个元素
		}
		else {
			copy[indexCopy--] = data[j--];
		}
	}
	// 处理未复制进copy中的元素
	for (; i >= start; --i) {
		copy[indexCopy--] = data[i];
	}
	for (; j >= start + length + 1; --j) {
		copy[indexCopy--] = data[j];
	}

	return (left + right + count); 
}
