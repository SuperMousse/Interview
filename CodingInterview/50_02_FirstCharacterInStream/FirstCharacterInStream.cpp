// 解法一: 剑指offer解法
class Solution
{
public:
	Solution() : index(0) {
		for (int i = 0; i < 256; ++i) {
			occurrence[i] = -1;
		}
	}

	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (occurrence[ch] == -1) {
			occurrence[ch] = index;
		}
		else if (occurrence[ch] >= 0) {
			occurrence[ch] = -2;
		}
		++index;
	}

	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char ch = '\0';
		int minIndex = INT_MAX;
		for (int i = 0; i < 256; ++i) {
			if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}

		if (ch == '\0') {
			return '#'; // 如果不存在出现一次的字符, 返回'#'
		}
		return ch;
	}
private:
	// occurrence[i]: A character with ASCII value i
	// occurrence[i] = -1: The character has not found
	// occurrence[i] = -2: The character has been found for mutiple times
	// occurrence[i] >= 0: The character has been found only once
	int occurrence[256];
	int index;
};

// 解法二: 牛客网解法
// occurrence统计字符的词频, 若第一次出现, 则将其频次+1, 并入队列
// 判断队首元素是否只出现了一次, 若出现多次则出队列

class Solution {
public:
	Solution() {
		memset(occurrence, 0, sizeof(occurrence));
	}

	//Insert one char from stringstream
	void Insert(char ch)
	{
		++occurrence[ch]; // 字符频次+1
		if (occurrence[ch] == 1) {
			data.push(ch);// 若第一次出现则加入队列
		}
	}

	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!data.empty() && occurrence[data.front()] >= 2) {
			data.pop();
		}
		if (data.empty()) {
			return '#';
		}
		return data.front();
	}

private:
	queue<char> data;
	int occurrence[256];
};
