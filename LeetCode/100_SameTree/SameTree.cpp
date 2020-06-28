bool isSameTree(TreeNode* p, TreeNode* q) {
    // 全都nullptr
    if (p == nullptr && q == nullptr) {
        return true;
    }
    // 某一个是nullptr, 另外一个不是
    if (p == nullptr || q == nullptr) {
        return false;
    }
    // 全都不是nullptr
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
