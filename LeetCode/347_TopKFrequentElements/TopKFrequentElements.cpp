// 桶排序
// 统计词频， 然后将词频作为对应的桶的索引, 在桶中存放数值
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<vector<int> > bucket(nums.size() + 1, vector<int>());
    unordered_map<int, int> hash;
    for (int n : nums) {
        hash[n] += 1;
    }

    unordered_map<int, int>::iterator itr;
    for (itr = hash.begin(); itr != hash.end(); ++itr) {
        int frequency = hash[itr->first];
        bucket[frequency].push_back(itr->first);
    }

    vector<int> res;
    for (int i = bucket.size() - 1; i >= 0 && res.size() < k; --i) {
        if (bucket[i].size() > 0) {
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }
    }
    return vector<int>(res.begin(), res.begin() + k);
}
