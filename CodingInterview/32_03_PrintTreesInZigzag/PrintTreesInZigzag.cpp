struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

// 二叉树之字形打印并分层
void PrintFromTopToBottom(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	stack<TreeNode*> levels[2];
	int current = 0;
	int next = 1;
	levels[current].push(root);
	while (!levels[0].empty() && !levels[1].empty()) {
		TreeNode* pNode = levels[current].top();
		levels[current].pop();
		cout << pNode->val;

		if (current == 0) {
			if (pNode->left != nullptr) {
				levels[next].push(pNode->left);
			}
			if (pNode->right != nullptr) {
				levels[next].push(pNode->right);
			}
		}
		else {
			if (pNode->right != nullptr) {
				levels[next].push(pNode->right);
			}
			if (pNode->left != nullptr) {
				levels[next].push(pNode->left);
			}
		}

		if (levels[current].empty()) {
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
	return;

}
