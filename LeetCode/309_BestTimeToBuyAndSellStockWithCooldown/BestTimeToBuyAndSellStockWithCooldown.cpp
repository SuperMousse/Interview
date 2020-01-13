// 三状态dp, s0: 手上没股票, 可以执行buy or rest动作, but->s1, rest->s0
//          s1: 执行buy动作后到达该状态, 手上有股票没卖, 可以执行sell or rest动作, sell->s2, rest->s1,
//          s2: 执行sell动作后到达该状态, 手上无股票, 必须休息, 只能执行rest动作, rest->s0
// 最后受益为s0和s2中的最大值, 因为最终手上必须没有股票, 这两个状态手上没股票
int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1) {
        return 0;
    }
    vector<int> s0(prices.size(), 0);
    vector<int> s1(prices.size(), 0);
    vector<int> s2(prices.size(), 0);
    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = INT_MIN;
    for (int i = 1; i < prices.size(); ++i) {
        s0[i] = max(s0[i - 1], s2[i - 1]);
        s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
        s2[i] = s1[i - 1] + prices[i];
    }

    return max(s0[prices.size() - 1], s2[prices.size() - 1]);
}
