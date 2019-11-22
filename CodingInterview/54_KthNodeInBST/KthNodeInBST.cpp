// 递归中序遍历

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k <= 0) {
		return nullptr;
	}
	vector<TreeNode*> result;
	KthNodeCore(pRoot, k, result);

	if (k > result.size()) {
		return nullptr;
	}
	return result[k - 1];
}

void KthNodeCore(TreeNode* pRoot, int k, vector<TreeNode*>& result) {
	if (pRoot == nullptr) {
		return;
	}
	if (pRoot->left != nullptr) {
		KthNodeCore(pRoot->left, k, result);
	}
	result.push_back(pRoot);
	if (pRoot->right != nullptr) {
		KthNodeCore(pRoot->right, k, result);
	}

	return;
}

// 非递归中序遍历
