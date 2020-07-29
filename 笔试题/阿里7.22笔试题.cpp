// 题一

// 给一个n（<=10），按字典序输出1~n的排列, 且排列中相邻数字绝对值不为1
// 输入：
// 4
// 输出：
// 2 4 1 3
// 3 1 4 2
// 分析: 1~4的全排列总计24种, 共两种解法符合要求

void dfs(vector<int>& visited, vector<vector<int> >& result, vector<int> temp,
        int N, int curNum) {
    visited[curNum] = 1;
    temp.push_back(curNum);
    if (temp.size() == N) {
        visited[curNum] = 0;
        result.push_back(temp);
        return;
    }
    for(int i = 1; i <= N; ++i){
        if (abs(curNum - i) != 1 && visited[i] == 0) {
            dfs(visited, result, temp, N, i);
        }
    }
    visited[curNum] = 0;
}

void generatePermutation(int N) {
    if (N < 1 || N > 10) {
        return;
    }
    vector<int> visited(11, 0);
    vector<vector<int> > result;
    vector<int> temp;
    for (int i = 1; i <= N; ++i) {
        dfs(visited, result, temp, N, i);
    }
    sort(result.begin(), result.end());
    for (auto r : result) {
        for (auto n : r) {
            cout << n << " ";
        }
        cout << endl;
    }
}

int main() {

    int N = 0;
    cin >> N;
    generatePermutation(N);
    return 0;
}




// 题二
// 给一个n个数字（1e5）。求有多少个区间出现最多的数字的次数大于等于m
// 输入：
// 5 2
// 1 2 1 2 5
// 输出：
// 5
// 分析: 区间[1, 3]中含有元素[1, 2, 1], 1出现次数
// 区间[1,3][1,4][1,5][2,4][2,5]五个区间中最多的数字大于2


// 枚举区间左端点。set维护一下出现最多的次数
int findInterval(vector<int> nums, int n, int m) {
    if (nums.empty() || m > n) {
        return -1;
    }
    int result = 0;
    multiset<int> numSet;
    unordered_map<int, int> hash; // 数字出现次数
    int right = 0;
    for (int i = 0; i < n; ++i) {
        while (right < n && (numSet.empty() || -*numSet.begin() < m)) {
            if (numSet.find(-hash[nums[right]]) != numSet.end()) {
                numSet.erase(numSet.find(-hash[nums[right]]));
            }
            ++hash[nums[right]];
            numSet.insert(-hash[nums[right]]);
            ++right;
        }
        if (!numSet.empty() && -*numSet.begin() >= m) {
            result += (n - right + 1); // 如果[1, 2]区间满足要求, 那么[1, 3], [1, 4]区间也都满足要求
        }
        // 当前区间向右移动, 删除numSet中的对应值和hash中的计数
        if (numSet.find(-hash[nums[i]]) != numSet.end()) {
            numSet.erase(numSet.find(-hash[nums[i]]));
        }
        --hash[nums[i]];
        numSet.insert(-hash[nums[i]]);
    }
    return result;
}

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int res = findInterval(nums, n, m);
    cout << res << endl;
}
