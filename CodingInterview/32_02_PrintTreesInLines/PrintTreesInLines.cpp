struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

// 二叉树逐层打印并分层
void PrintFromTopToBottom(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	queue<TreeNode*> queueTreeNode;
	queueTreeNode.push(root);
	int toBePrinted = 1; // 记录待打印节点数目
	int nextLevel = 0; // 记录下一层的节点数目
	while (!queueTreeNode.empty())
	{
		TreeNode* pNode = queueTreeNode.front();
		queueTreeNode.pop();
		cout << pNode->val;
		--toBePrinted;
		if (pNode->left != nullptr) {
			queueTreeNode.push(pNode->left);
			++nextLevel;
		}
		if (pNode->right != nullptr) {
			queueTreeNode.push(pNode->right);
			++nextLevel;
		}
		if (toBePrinted == 0) {
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
	return;
}
