vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> hash;
    vector<int> result;
    for (int n : nums1) {
        hash[n] += 1;
    }
    for (int n : nums2) {
        if (hash.count(n)) {
            result.push_back(n);
            hash[n] -= 1;
            if (hash[n] == 0) {
                hash.erase(n);
            }
        }
    }
    return result;
}
