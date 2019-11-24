// 书上解法
// 本题需注意, 书上解法在初始化时必须小心, 书上的pProbabilities初始化是正确的
// 若想要改成memset, 则需要写成memset(pProbabilities, 0, (maxSum-number+1)*sizeof(int)), 否则无法正常初始化



// 改良解法, 使用vector储存pProbabilities
vector<int> PrintProbability(int number) {
	vector<int> result;
	if (number < 1) {
		return result;
	}

	int g_maxValue = 6;
	int maxSum = number * g_maxValue;
	vector<int> pProbabilities(maxSum - number + 1, 0);

	Probability(number, pProbabilities, g_maxValue);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i) {
		double ratio = (double)pProbabilities[i - number] / total;
		result.push_back(ratio);
		cout << ratio << endl;
	}

	return result;
}


void Probability(int number, vector<int>& pProbabilities, int g_maxValue) {
	// 初始骰子选1~6中的一个
	for (int i = 1; i <= g_maxValue; ++i) {
		Probability(number, number, i, pProbabilities, g_maxValue);
	}
}

void Probability(int original, int current, int sum, vector<int>& pProbabilities, int g_maxValue) {
	if (current == 1) {
		++pProbabilities[sum - original]; // original为骰子个数, 用于换算数组位置
	}
	else {
		// 向前一步, current-1, i+sum
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities, g_maxValue);
		}
	}
}
