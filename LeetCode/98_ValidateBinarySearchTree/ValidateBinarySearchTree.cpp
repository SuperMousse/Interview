// 解法一：中序遍历+递归
	bool isValidBST(TreeNode* root) {
		TreeNode* prev = nullptr;
		return helper(root, prev);
	}

	bool helper(TreeNode* root, TreeNode*& prev) {
		if (root == nullptr) {
			return true;
		}
		if (helper(root->left, prev) == false) {
			return false;
		}
		if (prev != nullptr && prev->val >= root->val) {
			return false;
		}
		prev = root;
		return helper(root->right, prev);
	}
  
  
  // 解法二：中序遍历+循环
bool isValidBST(TreeNode* root) {
	if (root == nullptr) {
		return true;
	}
	TreeNode* pNode = root;
	TreeNode* prev = nullptr;
	stack<TreeNode*> stackTreeNode;
	while (pNode != nullptr || !stackTreeNode.empty()) {
		while (pNode != nullptr) {
			stackTreeNode.push(pNode);
			pNode = pNode->left;
		}
		pNode = stackTreeNode.top();
		stackTreeNode.pop();
		if (prev != nullptr && pNode->val <= prev->val) {
			return false;
		}
		prev = pNode;
		pNode = pNode->right;
	}
	return true;
}
