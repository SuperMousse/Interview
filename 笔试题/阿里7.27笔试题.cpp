// 题一
// 纸上写了一个单调非递减的数字序列，每个人依次选择一个数字，然后把这个数字第一次出现位置及其之前的数字都删掉，
// 直到谁把序列删除空谁就赢了，niuniu先手，niumei后手，谁赢打印谁的名字。
// 输入：
// T 表示有几组数据
// n 表示每组序列中有几个数
// 接下来一行为序列
// 样例：
// 1
// 6
// 111222
// 输出：niuniu
// 原因：niuniu选2，序列变为22；niumei选2，序列变为2；niuniu选2，序列变为空，niuniu赢

// 分析: 当所有数字都为偶数的时候第二个人才胜利, 否则都是第一个人胜利
// 当某一个人拿完之后还剩两个数字的时候, 这个人必胜; 推导出某个人拿完之后还剩1122的时候, 这个人也必胜;
// 当某个人拿完之后还剩一个数字的时候, 这个人必败
// 当所有数字都为偶数的时候, 第一个人必须把偶数数字留下一个, 那么第二个人就可以把剩下的结果凑成偶数个, 第二个人必胜

// 当数字序列中有奇数的时候, 第一个人可以在末端的最后一组奇数上开始拿, 1122233, 拿了2之后变成2233, 第一个人必胜

void findWinner(vector<vector<char>> nums) {
    if (nums.empty()) {
        return;
    }
    int rows = nums.size();
    int cols = nums[0].size();
    bool flag = false;
    for (int i = 0; i < rows; ++i) {
        unordered_map<int, int> hash;
        flag = false;
        for (int j = 0; j < cols; ++j) {
            hash[nums[i][j]] += 1;
        }
        for (auto beg = hash.begin(); beg != hash.end(); ++beg) {
            if (beg->second % 2 != 0) {
                cout << "Person 1 win" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Person 2 win" << endl;
        }
    }
    return;
}


int main() {

    int T = 0;
    int n = 0;
    vector<vector<char>> nums;
    cin >> T;
    cin >> n;
    while (T--) {
        vector<char> tempVec;
        for (int i = 0; i < n; ++i) {
            char tempNum = 0;
            cin >> tempNum;
            tempVec.push_back(tempNum);
        }
        nums.push_back(tempVec);
    }
    findWinner(nums);

    return 0;

}




// 题二
// https://www.nowcoder.com/discuss/460859?type=2
