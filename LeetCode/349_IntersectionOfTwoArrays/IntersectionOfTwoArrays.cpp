  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> hash1(nums1.begin(), nums1.end());
      vector<int> result;
      for (int n : nums2) {
          if (hash1.count(n) != 0) {
              result.push_back(n);
              hash1.erase(n);
          }
      }
      return result;
  }
