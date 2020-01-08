// 后序遍历
void flatten(TreeNode* root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }
    TreeNode* pre = nullptr;
    helper(root, pre);
    return;
}

TreeNode* helper(TreeNode* root, TreeNode*& pre) {
    if (root == nullptr) {
        return pre;
    }
    pre = helper(root->right, pre); // 后序遍历
    pre = helper(root->left, pre);
    root->right = pre;
    root->left = nullptr;
    pre = root;
    return pre;
}
