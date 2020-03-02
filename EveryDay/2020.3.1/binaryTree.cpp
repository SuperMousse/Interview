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

// 从二叉树的先序好中序序列中重构二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty() ||
        preorder.size() != inorder.size()) {
        return nullptr;
    }
    int length = preorder.size();
    TreeNode* head = helper(preorder, inorder, 0, length - 1, 0, length - 1);
    return head;
}
TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                 int beginPre, int endPre, int beginIn, int endIn) {
    int rootVal = preorder[beginPre];
    TreeNode* root = new TreeNode(rootVal);
    root->left = root->right = nullptr;
    if (beginPre == endPre) {
        if (preorder[beginPre] = preorder[endPre]) {
            return root;
        }
        else {
            throw runtime_error("sth wrong");
        }
    }
    int rootInIndex = beginIn;
    while (rootInIndex <= endIn && inorder[rootInIndex] != rootVal) {
        ++rootInIndex;
    }
    if (rootInIndex == endIn && inorder[rootInIndex] != inorder[endIn]) {
        throw runtime_error("sth wrong");
    }
    int leftLength = rootInIndex - beginIn;
    int leftEndPre = beginPre + leftLength;

    if (leftLength > 0) {
        root->left = helper(preorder, inorder,
                            beginPre+1, leftEndPre, beginIn, rootInIndex-1);
    }
    if (beginPre + leftLength < endPre) {
        root->right = helper(preorder, inorder,
                             leftEndPre+1, endPre, rootInIndex+1, endIn);
    }
    return root;
}
