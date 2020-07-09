bool isBalancedCore(TreeNode* root, int& depth) {
    if (root == nullptr) {
        return true;
    }
    int left = 0;
    int right = 0;
    if (isBalancedCore(root->left, left) && isBalancedCore(root->right, right)) {
        int diff = abs(left - right);
        if (diff <= 1) {
            depth = max(left, right) + 1;
            return true;
        }
    }
    return false;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    int depth = 0;
    return isBalancedCore(root, depth);
}
