// 递归中序遍历
// 借助vector<TreeNode*> , 空间占用略高, 使用计数器可以节省空间复杂度

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
	if (result.size() == k) {
		return;
	}
	if (pRoot->right != nullptr) {
		KthNodeCore(pRoot->right, k, result);
	}

	return;
}

// 非递归中序遍历
// 借助vector<TreeNode*> 而不是使用计数器
void KthNodeCore(TreeNode* pRoot, int k, vector<TreeNode*>& result) {
	if (pRoot == nullptr) {
		return;
	}
	stack<TreeNode*> stackTreeNode;
	TreeNode* pNode = pRoot;
	while (pNode != nullptr || !stackTreeNode.empty()) {
		while (pNode != nullptr) {
			stackTreeNode.push(pNode);
			pNode = pNode->left;
		}
		if (!stackTreeNode.empty()) {
			pNode = stackTreeNode.top();
			stackTreeNode.pop();
			result.push_back(pNode);
			if (result.size() == k) {
				return;
			}
			pNode = pNode->right;
		}

	}


	return;
}


// 递归中序遍历, 使用计数器
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k <= 0) {
		return nullptr;
	}
	int count = 0;
	TreeNode* pResult = KthNodeCore(pRoot, k, count);

	return pResult;
}

TreeNode* KthNodeCore(TreeNode* pRoot, int k, int& count) {
	if (pRoot == nullptr || k <= 0) {
		return nullptr;
	}

	TreeNode* pNode = nullptr;
	pNode = KthNodeCore(pRoot->left, k, count);

	// 递归标记找到了这个节点
	if (pNode != nullptr) {
		return pNode;
	}

	++count; // 根节点计数
	if (count == k) {
		return pRoot;
	}

	pNode = KthNodeCore(pRoot->right, k, count);

	if (pNode != nullptr) {
		return pNode;
	}

	return nullptr;
}



// 非递归中序遍历, 使用计数器

TreeNode* KthNodeCore(TreeNode* pRoot, int k, int& count) {
	if (pRoot == nullptr || k <= 0) {
		return nullptr;
	}
	stack<TreeNode*> stackTreeNode;
	TreeNode* pNode = pRoot;
	
	while (pNode != nullptr || !stackTreeNode.empty()) {
		while (pNode != nullptr) {
			stackTreeNode.push(pNode);
			pNode = pNode->left;
		}
		if (!stackTreeNode.empty()) {
			pNode = stackTreeNode.top();
			stackTreeNode.pop();
			++count;
			if (count == k) {
				return pNode;
			}
			pNode = pNode->right;
		}
	}
	return nullptr;
}
