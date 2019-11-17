struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 先序遍历来解决这个问题
vector<vector<int> > find(TreeNode* root, int expectNumber, vector<int> &path, int currentSum);

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int>> result;
	if (root == nullptr) {
		return result;
	}
	vector<int> path;
	int currentSum = 0;
	find(root, expectNumber, result, path, currentSum);
	return result;
}

void find(TreeNode* root, int expectNumber, 
	      vector<vector<int> >& result, vector<int>& path, int currentSum) {
	if (root == nullptr) {
		return;
	}
	currentSum += root->val;
	path.push_back(root->val);

	// 如果是叶子节点，并且路径上节点值的和等于输入的值，加入result
	bool isLeaf = (root->left == nullptr && root->right == nullptr);
	if (currentSum == expectNumber && isLeaf) {
		result.push_back(path);
	}
	else {
		// 如果不是叶子节点，则遍历它的所有子节点
		if (root->left != nullptr) {
			find(root->left, expectNumber, result, path, currentSum);
		}
		if (root->right != nullptr) {
			find(root->right, expectNumber, result, path, currentSum);
		}
	}

	// 在返回父节点之前，在路径上删除当前节点
	path.pop_back();

	return;
}
