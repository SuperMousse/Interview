// O(n)解法
int kthFactor(int n, int k) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++count;
        }
        if (count == k) {
            return i;
        }
    }
    return -1;
}


// O(sqrt(n))解法
int kthFactor(int n, int k) {
    int count = 0;
    vector<int> data; // data中存储了大于sqrt(n)的因子, count计算了小于sqrt(n)的因子
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i != n) {
                data.push_back(n / i);
            }
            if (++count == k) {
                return i;
            }
        }
    }
    if (data.size() + count < k) {
        return -1;
    }
    // data.size() + count >= k, 说明第k个因子大于sqrt(n)
    // 第k个因子是大于sqrt(n)的第(k - count)个, data倒序存储直接索引即可
    return data[data.size() - (k - count)];
}
