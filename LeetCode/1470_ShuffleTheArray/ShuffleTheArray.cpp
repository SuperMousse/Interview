vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res(2*n, 0);
    for (int i = 0; i < 2*n; ++i) {
        if (i % 2 == 0) {
            res[i] = res[i / 2];
        }
        else {
            res[i] = res[i / 2 + n];
        }
    }
    return res;
}
