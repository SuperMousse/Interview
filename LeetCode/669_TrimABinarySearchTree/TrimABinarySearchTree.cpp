修剪二叉搜索树节点到L，R之间

TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == nullptr) {
            return root;
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        else if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        else {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
