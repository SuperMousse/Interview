struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


// 递归
void Mirror(TreeNode* pRoot) {
	// pRoot is null
	if (pRoot == nullptr) {
		return;
	}
	// only sigle node 
	if (pRoot->left == nullptr && pRoot->right == nullptr) {
		return;
	}

	TreeNode* pTemp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = pTemp;

	// mirror if the node is not a leaf node
	if (pRoot->left != nullptr) {
		Mirror(pRoot->left);
	}
	if (pRoot->right != nullptr) {
		Mirror(pRoot->right);
	}
	return;
}

// 非递归->循环
void Mirror(TreeNode* pRoot) {
	// pRoot is null
	if (pRoot == nullptr) {
		return;
	}
	// only sigle node 
	if (pRoot->left == nullptr && pRoot->right == nullptr) {
		return;
	}

	stack<TreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);

	while (stackTreeNode.size() > 0) {
		TreeNode* pNode = stackTreeNode.top();
		stackTreeNode.pop();

		TreeNode* pTemp = pNode->left;
		pNode->left = pNode->right;
		pNode->right = pTemp;

		if (pNode->left) {
			stackTreeNode.push(pNode->left);
		}
		if (pNode->right != nullptr) {
			stackTreeNode.push(pNode->right);
		}
	}
	return;
}
