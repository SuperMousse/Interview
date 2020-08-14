TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* pLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode* pRight = lowestCommonAncestor(root->right, p, q);
    if (pLeft == nullptr) {
        return pRight;
    }
    else if (pRight == nullptr) {
        return pLeft;
    }
    else {
        return root;
    }
}
