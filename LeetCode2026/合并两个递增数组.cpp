class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0 || nums2.empty()) {
            return;
        }
        int pointer1 = m-1;
        int pointer2 = n-1;
        int pointer = m + n -1;
        while(pointer2>=0) {
            if(pointer1 >= 0 && nums1[pointer1] > nums2[pointer2]) {
                nums1[pointer] = nums1[pointer1];
                pointer1--;
                pointer--;
            } else {
                nums1[pointer] = nums2[pointer2];
                pointer2--;
                pointer--;
            }
        }
        return;
    }
};
