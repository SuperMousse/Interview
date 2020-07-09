bool isSameTree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
        return true;
    }
    if (s == nullptr || t == nullptr) {
        return false;
    }
    if (s->val != t->val) {
        return false;
    }
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}



bool isSubtree(TreeNode* s, TreeNode* t) {
    if (t == nullptr) {
        return true;
    }
    if (s == nullptr) {
        return false;
    }
    if (isSameTree(s, t)) {
        return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);

}
