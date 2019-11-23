vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (num.size() < size || size < 1) {
		return result;
	}

	deque<int> index;
	for (unsigned int i = 0; i < size; ++i)
	{
		// 是否将较小的索引抛出, 以保证队头一定是最大的索引
		while (!index.empty() && num[i] >= num[index.back()]) {
			index.pop_back();
		}
		index.push_back(i);
	}

	for (unsigned int i = size; i < num.size(); ++i)
	{
		result.push_back(num[index.front()]);

		while (!index.empty() && num[i] >= num[index.back()]) {
			index.pop_back();
		}
		// 将超出滑动窗口的范围的index抛出
		if (!index.empty() && index.front() <= (int)(i - size)) {
			index.pop_front();
		}

		index.push_back(i);
	}
	result.push_back(num[index.front()]);

	return result;
}
