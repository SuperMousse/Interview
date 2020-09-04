

vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return vector<int>();
    }
    vector<int> result;
    stack<TreeNode*> stackTree;
    TreeNode* pNode = root;
    TreeNode* pPrev = nullptr;
    while (!stackTree.empty() || !pPrev) {
        while (pNode) {
            stackTree.push(pNode);
            pNode = pNode->left;
        }
        pNode = stackTree.top();
        // 右节点访问过或者是空, 将根节点打印并且弹出
        if (pNode->right == nullptr || pNode->right == pPrev) {
            result.push_back(pNode->val);
            stackTree.pop();
            // 记录上一个访问过的节点, 用于判断访问根节点之前, 右子树是否已经访问过
            pPrev = pNode;
            // 表示不需要转向右子树, 继续弹出
            pNode = nullptr;
        }
        else {
            pNode = pNode->right;
        }
    }
    return result;
}
