class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        int length = nums.size();
        TreeNode* pHead = helper(nums, 0, length - 1);
        return pHead;
    }

    TreeNode* helper(vector<int>& nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int middle = low + (high - low) / 2;
        TreeNode* pNode = new TreeNode(nums[middle]);
        pNode->left = helper(nums, low, middle - 1);
        pNode->right = helper(nums, middle + 1, high);
        return pNode;
    }
};
