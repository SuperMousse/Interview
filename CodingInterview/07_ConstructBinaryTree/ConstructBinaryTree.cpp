struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

using it = vector<int>::iterator;
TreeNode* ConstructCore(it startPreorder, it endPreorder, it startInorder, it endInorder);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.empty() || vin.empty()) {
		return nullptr;
	}
	return ConstructCore(pre.begin(), pre.end()-1, vin.begin(), vin.end()-1);
}

TreeNode *ConstructCore(it startPreorder, it endPreorder, it startInorder, it endInorder) {
	// The first number in Preorder sequence is root number.
	int rootValue = *startPreorder;
	TreeNode* root = new TreeNode(rootValue);
	root->left = root->right = nullptr;
	if (startPreorder == endPreorder) {
		if (startPreorder == endPreorder && *startPreorder == *endPreorder) {
			return root;
		}
		else {
			throw exception("Invalid Input");
		}
	}
	//find root number in Inorder sequence.
	it rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue) {
		++rootInorder;
	}
	if (rootInorder == endInorder && *rootInorder != rootValue) {
		throw exception("Invalid Input");
	}

	int leftLength = rootInorder - startInorder;
	it leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0) {
		// construct left subtree
		root->left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	if(leftLength<endPreorder-startPreorder){
		// construct right subtree
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder+1, endInorder);
	}

	return root;
}
