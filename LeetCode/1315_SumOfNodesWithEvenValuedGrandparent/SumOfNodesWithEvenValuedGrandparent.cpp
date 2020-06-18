int sumEvenGrandparent(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int sum = 0;
    dfs(root, nullptr, nullptr, sum);
    return sum;
}

void dfs(TreeNode* root, TreeNode* parent, TreeNode* grandParent, int& sum) {
    if (!root) {
        return;
    }
    if (!grandParent && grandParent->val % 2 == 0) {
        sum += root->val;
    }
    dfs(root->left, root, parent, sum);
    dfs(root->right, root, parent, sum);
    return;
}
