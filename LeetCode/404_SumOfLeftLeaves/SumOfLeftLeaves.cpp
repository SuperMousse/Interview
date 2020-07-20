// 递归
int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int sum = 0;
    if (root->left != nullptr) {
        if (root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        else {
            sum += sumOfLeftLeaves(root->left);
        }
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
}




// 非递归
