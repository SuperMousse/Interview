void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) {
      return;
    }
    if (m == 0) {
      nums1[0] = nums2[0];
    }
    int pt1 = m - 1;
    int pt2 = n - 1;
    int pCurrent = m + n - 1;
    while (pt1 >= 0 && pt2 >= 0) {
      if (nums2[pt2] >= nums1[pt1]) {
        nums1[pCurrent--] = nums2[pt2--];
      }
      else {
        nums1[pCurrent--] = nums1[pt1--];
      }
    }

    while (pt1 >= 0) {
      nums1[pCurrent--] = nums1[pt1--];
    }
    while (pt2 >= 0) {
      nums1[pCurrent--] = nums2[pt2--];
    }

    return;
}
