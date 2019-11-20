
//递归方法求解八皇后过程
vector<vector<int> > eightQueen(int k)
{
	vector<vector<int>> result;
	if (k <= 0) {
		return result;
	}
	vector<int> queen(k, 0);
	int position = 0;
	hasEightQueen(result, queen, k, position);

	return result;
}

void hasEightQueen(vector<vector<int>>& result, vector<int>& queen, int k, int position) {
	if (position == k) {
		result.push_back(queen);
		return;
	}
	for (int col = 0; col < k; ++col) {
		queen[position] = col;
		if (canPlaceQueen(queen, position)) {
			hasEightQueen(result, queen, k, position + 1);
		}
	}
}

//剪枝函数
bool canPlaceQueen(vector<int> queen, int position)
{
	for (int i = 0; i < position; ++i)
	{
		//判断是否处于同一列或同一斜线
		if (queen[i] == queen[position] || abs(position - i) == abs(queen[position] - queen[i]))
			return false;
	}
	return true;
}

/*******************************************************************************************************/
//迭代方法求解八皇后过程
vector<vector<int> > eightQueen(int k)
{
	vector<vector<int>> result;
	if (k <= 0) {
		return result;
	}
	vector<int> queen(k, -1);
	int position = 0;
	hasEightQueen(result, queen, k, position);

	cout << result.size();
	return result;
}

void hasEightQueen(vector<vector<int>> & result, vector<int> & queen, int k, int position) {
	while (position >= 0) {
		queen[position] += 1;
		while ((queen[position] < k) && (!canPlaceQueen(queen, position))) //搜索第position个皇后位置
		{
			queen[position] = queen[position] + 1;
		}

		if (queen[position] < k)//找到了合理的位置
		{
			if (position == (k - 1))
			{
				result.push_back(queen); //找到一组解
			}
			else
			{
				position = position + 1;//继续为第k+1个皇后找到位置，对应下一级循环 
				queen[position] = -1;//下一个皇后一定要从头开始搜索
			}
		}
		else
		{
			--position;//回溯
		}
	}
	return;
}
