struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

using it = vector<int>::iterator;
TreeNode* ConstructCore(it startPreorder, it endPreorder, it startInorder, it endInorder);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.empty() || vin.empty() || (pre.size()!=vin.size()) {
		return nullptr;
	}
	return ConstructCore(pre.begin(), pre.end()-1, vin.begin(), vin.end()-1);
}

TreeNode* ConstructCore(it startPreorder, it endPreorder, it startInorder, it endInorder) {
	int rootValue = *startPreorder;
    	TreeNode* root = new TreeNode(rootValue);
    	root->left = root->right = nullptr;
    	// The first number in Preorder sequence is root number
    	if (startPreorder == endPreorder) {
    		if (startPreorder == endPreorder && *startPreorder == *endPreorder) {
    			return root;
    		}
    		else {
    			throw runtime_error("Invalid Input");
    		}
    	}

	    // find root number in Inorder sequence
    	it rootInorder = startInorder;
    	while (rootInorder <= endInorder && *rootInorder != rootValue)
	    	++rootInorder;
    	if (rootInorder == endInorder && *rootInorder != rootValue)
	    	throw runtime_error("Invalid Input");

	    int leftLength = rootInorder - startInorder;
	    it leftPreorderEnd = startPreorder + leftLength;
	    //construct left subtree
	    if (leftLength > 0) {
	    	root->left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	    }
	    // construct right subtree
	    if (leftLength < (endPreorder - startPreorder)) {
	    	root->right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	    }
	    return root;
}
