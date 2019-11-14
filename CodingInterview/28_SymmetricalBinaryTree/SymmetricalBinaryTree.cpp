
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 递归
bool isSymmetrical(TreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (pRoot1 == nullptr && pRoot2 == nullptr) {
		return true;
	}
	if (pRoot1 == nullptr || pRoot2 == nullptr) {
		return false;
	}
	if (pRoot1->val != pRoot2->val) {
		return false;
	}
	return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
}


// depth first search
bool isSymmetricalDFS(TreeNode* pRoot)
{
	if (pRoot == nullptr) {
		return true;
	}
	stack<TreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot->left);
	stackTreeNode.push(pRoot->right);
	while (!stackTreeNode.empty()) {
		TreeNode* right = stackTreeNode.top();
		stackTreeNode.pop();
		TreeNode* left = stackTreeNode.top();
		stackTreeNode.pop();
		if (left == nullptr && right == nullptr) {
			continue;
		}
		if (left == nullptr || right == nullptr) {
			return false;
		}
		if (left->val != right->val) {
			return false;
		}
		// 成对插入
		stackTreeNode.push(left->left);
		stackTreeNode.push(right->right);
		stackTreeNode.push(left->right);
		stackTreeNode.push(right->left);
	}
	return true;
}



// breadth first search
bool isSymmetricalBFS(TreeNode* pRoot)
{
	if (pRoot == nullptr) {
		return true;
	}
	queue<TreeNode*> queueTreeNode;
	queueTreeNode.push(pRoot->left);
	queueTreeNode.push(pRoot->right);
	while (!queueTreeNode.empty()) {
		TreeNode* right = queueTreeNode.front();
		queueTreeNode.pop();
		TreeNode* left = queueTreeNode.front();
		queueTreeNode.pop();
		if (left == nullptr && right == nullptr) {
			continue;
		}
		if (left == nullptr || right == nullptr) {
			return false;
		}
		if (left->val != right->val) {
			return false;
		}
		// 成对插入
		queueTreeNode.push(left->left);
		queueTreeNode.push(right->right);
		queueTreeNode.push(left->right);
		queueTreeNode.push(right->left);
	}
	return true;
}

