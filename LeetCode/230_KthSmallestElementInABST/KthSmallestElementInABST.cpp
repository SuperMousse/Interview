int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stackTreeNode;
    TreeNode* pNode = root;
    while (pNode || !stackTreeNode.empty()) {
        while(pNode) {
            stackTreeNode.push(pNode);
            pNode = pNode->left;
        }
        if (!stackTreeNode.empty()) {
            pNode = stackTreeNode.top();
            stackTreeNode.pop();
            --k;
            if (k == 0) {
                return pNode->val;
            }
            pNode = pNode->right;

        }
    }
    return -1;
}
