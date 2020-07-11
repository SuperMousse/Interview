vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) {
        return vector<int>();
    }
    vector<int> result;
    queue<TreeNode*> queueTreeNode;
    queueTreeNode.push(root);
    while (!queueTreeNode.empty()) {
        int curLen = queueTreeNode.size();
        for (int i = 0; i < curLen; ++i) {
            TreeNode* pNode = queueTreeNode.front();
            queueTreeNode.pop();
            if (pNode->left) {
                queueTreeNode.push(pNode->left);
            }
            if (pNode->right) {
                queueTreeNode.push(pNode->right);
            }
            if (i == (curLen - 1)) {
                result.push_back(pNode->val);
            }
        }
    }
    return result;
}
