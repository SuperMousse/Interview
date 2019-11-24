// 解法一: 依次删除每一个元素, 使用list模拟环形链表
// 注意: list的迭代器不支持算数加减法, 只能自增或自减运算
// n < m的条件不应该加上, 因为环形所以可以多转一圈
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1) { // n < m
		return -1;
	}
	
	unsigned int i = 0;

	list<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}
	list<int>::iterator current = numbers.begin();

	while (numbers.size() > 1) {
		for (int i = 1; i < m; ++i) {
			++current;
			if (current == numbers.end()) {
				current = numbers.begin();
			}
		}
		list<int>::iterator next = ++current; // list迭代器只能自增自减,不能算数加法
		if (next == numbers.end()) {
			next = numbers.begin();
		}

		--current;
		numbers.erase(current);
		current = next;
	}

	return *current;
}
