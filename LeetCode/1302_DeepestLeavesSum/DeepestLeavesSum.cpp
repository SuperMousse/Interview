int deepestLeavesSum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    queue<TreeNode*> queueTreeNode;
    queueTreeNode.push(root);
    int res = 0;
    while(!queueTreeNode.empty()) {
        res = 0;
        int len = queueTreeNode.size();
        for (int i = 0; i < len; ++i) {
            TreeNode* pNode = queueTreeNode.front();
            queueTreeNode.pop();
            res += pNode->val;
            if (pNode->left) {
                queueTreeNode.push(pNode->left);
            }
            if (pNode->right) {
                queueTreeNode.push(pNode->right);
            }
        }
    }
    return res;
}
