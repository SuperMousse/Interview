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
