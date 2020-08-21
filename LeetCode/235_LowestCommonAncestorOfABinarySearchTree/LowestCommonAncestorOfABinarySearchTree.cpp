// 解法一: 



// 解法二: 不考虑二叉搜索树的特性, 单纯认为是二叉树上的公共祖先问题
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr) {
        return right;
    }
    else if (right == nullptr) {
        return left;
    }
    else {
        return root;
    }
}
