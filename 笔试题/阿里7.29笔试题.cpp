// 题一
// 给 n 个恐龙蛋及恐龙蛋的大小，按降序排列. 第i个恐龙蛋每天增大i, 问最少几天会出现两个同样大小的恐龙蛋

// 分析: 第i个恐龙蛋每天增大i, 第i+1个恐龙蛋每天增大i+1, 那么相邻的恐龙蛋的差距每天都会缩小1
// 如果初始的时候相邻恐龙蛋的差数组为[d_1, d_2, ..., d_n-1], 一天后差数组变为[d_1 - 1, d_2 - 1, ...]
// 那么经过一段时间后, 差数组中出现0元素的时候, 就表示首次出现两个相同大小的恐龙蛋, d首次出现0元素的时间就是
// 差数组中的最小值

int findDays(vector<int> eggs) {
    int len = eggs.size();
    int result = INT_MAX;
    for (int i = 0; i < len - 1; ++i) {
        int diff = eggs[i] - eggs[i+1];
        result = min(result, diff);
    }
    return result;
}


// 题二

// https://www.nowcoder.com/discuss/462000?type=2&channel=-2&source_id=discuss_terminal_discuss_hot 
// tuogy这个人还有其他题解
