// 该题实际上是在寻找局部的数组, 数组的起始为局部数组最小值, 终止为局部数组最大值
// { 7, 1, 2, 3, 6, 4 }中1~6的局部数组，只需要把1, 2, 3, 6的递增和分别加起来就可以了

int maxProfit(vector<int>& prices) {
	if (prices.empty()) {
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] > prices[i - 1]) {
			sum += prices[i] - prices[i - 1];
		}
	}
	return sum;
}
