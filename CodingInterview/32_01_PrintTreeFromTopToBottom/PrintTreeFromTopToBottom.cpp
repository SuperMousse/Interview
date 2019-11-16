// BFS
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 广度优先遍历二叉树
vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> result;
	queue<TreeNode*> queueTreeNode;
	if (root == nullptr) {
		return result;
	}
	result.push_back(root->val);
	queueTreeNode.push(root->left);
	queueTreeNode.push(root->right);
	while (!queueTreeNode.empty()) {
		TreeNode* pNode = queueTreeNode.front();
		queueTreeNode.pop();
		if (pNode != nullptr) {
			result.push_back(pNode->val);
			if (pNode->left != nullptr) {
				queueTreeNode.push(pNode->left);
			}
			if (pNode->right != nullptr) {
				queueTreeNode.push(pNode->right);
			}
		}
	}
	return result;
	
}



// 广度优先遍历有向图
