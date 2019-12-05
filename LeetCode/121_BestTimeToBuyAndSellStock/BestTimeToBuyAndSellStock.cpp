int maxProfit(vector<int>& prices) {
	if (prices.empty()) {
		return 0;
	}
	int minPrice = prices[0];
	int maxProfit = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i] < minPrice) {
			minPrice = prices[i];
		}
		int Profit = prices[i] - minPrice;
		if (Profit > maxProfit) {
			maxProfit = Profit;
		}
	}
	return maxProfit;
}
