int core(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }
    int left = max(core(root->left, maxSum), 0);
    int right = max(core(root->right, maxSum), 0);
    maxSum = max(maxSum, left + right + root->val);
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int maxSum = INT_MIN;
    core(root, maxSum);
    return maxSum;
}
