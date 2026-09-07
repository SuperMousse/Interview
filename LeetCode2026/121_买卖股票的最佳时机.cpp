class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int len = prices.size();
        for(int i = 0; i < len; i++) {
            // 更新minPrice
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                if ((prices[i] - minPrice ) > maxProfit)
                // 不是minPrice需要更新maxProfit
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};
