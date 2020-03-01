// 验证一个二叉树是否是二叉搜索树

bool isValidBST(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }
    stack<TreeNode*> stackTreeNode;
    TreeNode* pNode = root;
    TreeNode* pPrev = nullptr;
    // stackTreeNode.push(pNode); // push后需要移动, 不然下面push了两回
    while (pNode != nullptr || !stackTreeNode.empty()) {
        while (pNode != nullptr) {
            stackTreeNode.push(pNode);
            pNode = pNode->left;
        }
        pNode = stackTreeNode.top();
        stackTreeNode.pop();
        if (pPrev != nullptr && pNode->val <= pPrev->val) {
            return false;
        }
        pPrev = pNode;
        pNode = pNode->right;
    }
    return true;
}
