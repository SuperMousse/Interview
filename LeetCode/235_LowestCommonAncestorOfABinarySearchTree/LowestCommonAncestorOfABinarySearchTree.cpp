// 解法一: 
// 二叉搜索树上p, q的最低公共祖先为第一个在[p->val, q->val]之间的一个值

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* pCurrent = root;
    while (true) {
        // p->val, q->val均小于pCurrent->val
        if (p->val < pCurrent->val && q->val < pCurrent->val) {
            pCurrent = pCurrent->left;
        }
        else if (p->val > pCurrent->val && q->val > pCurrent->val) {
            pCurrent = pCurrent->right;
        }
        else {
            break;
        }
    }
    return pCurrent;
}


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
