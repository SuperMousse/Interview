// 普通的树, 寻找两节点的最低公共节点, 树不含有指向父节点的指针
// 判断当前节点的子树中是否含有搜索的节点, 若某节点的子节点中含有待搜索的节点,
// 但其子节点内却不含有待搜索的节点, 则该节点即为最低公共祖先
// 缺点: 搜索存在重复
// 检查左右子树是否包含想要找的节点， 如果左右子树都同时不包含要找的两个节点, 那么当前节点就是要找的节点


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
