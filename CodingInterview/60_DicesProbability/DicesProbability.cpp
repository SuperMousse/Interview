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

	double total = pow((double)g_maxValue, number);
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




// 动态规划的循环解法
vector<int> PrintProbability(int number) {
	vector<int> result;
	if (number < 1) {
		return result;
	}

	int g_maxValue = 6;
	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1]; //probabilities[*][0]是没用的，只是为了让下标对应点数
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
	{
		pProbabilities[flag][i] = 1; 	// 初始化第一个骰子各面出现次数, 初始化时flag=0存放次数, flag=1存放求和之后的次数
		                                // 此后使用flag存放前一状态的次数, 使用1-flag存放新的次数

		                                
	}

	// number为骰子个数, 从第二个骰子开始计算到第number个骰子
	for (int k = 2; k <= number; ++k) 
	{
		// 这里实际上是0~g_maxValue * k的循环拆解成了两次循环,0~k-1的位置上实际上不会产生实际数值,置零即可
		for (int i = 0; i < k; ++i)
		{
			pProbabilities[1 - flag][i] = 0; // 1-flag为当前的骰子, 把前面的数据清零
		}
		for (int i = k; i <= g_maxValue * k; ++i) // 投至第k个骰子时,最小和为k, 最大和为g_maxValue * k
		{
			pProbabilities[1 - flag][i] = 0;  // 延续前一次清零继续清零
			// j = 1~6, i-j>=0, 此处实际上为前一个骰子的六种状态的求和
			// 此处将j<=i修改为j<i(根据递推方程)
			for (int j = 1; j < i && j <= g_maxValue; ++j) {
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
			}
		}
		flag = 1 - flag;
	}


	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i) {
		double ratio = (double)pProbabilities[flag][i] / total;
		result.push_back(ratio);
		cout << ratio << endl;
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
	return result;
}
