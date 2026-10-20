class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) {
            return result;
        }
        unordered_map<int, int> intersection;
        for (auto& num : nums1) {
            intersection[num] = 1;
        }
        for (auto& num : nums2) {
            intersection[num] -= 1;
            if (intersection.find(num) != intersection.end() && intersection[num] == 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};
