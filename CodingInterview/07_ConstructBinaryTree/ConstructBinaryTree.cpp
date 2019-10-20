struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

using it = vector<int>::iterator;
TreeNode* ConstructCore(it startPreorder, it endPreorder, it startInorder, it endInorder);
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.empty() || vin.empty() || (pre.size()!=vin.size())) {
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



struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
	 if (pre.empty() || in.empty() || (pre.size()!=in.size()))
		 return nullptr;
	 int length = pre.size();
	 if (length == 0)
		 return nullptr;

	 vector<int> left_pre, right_pre, left_in, right_in;
	 //创建根节点，根节点肯定是前序遍历的第一个数
	 TreeNode * head = new TreeNode(pre[0]);
	 //找到中序遍历根节点所在位置,存放于变量root中
	 int root = 0;
	 for (int i = 0; i < length; i++)
	 {
		 if (in[i] == pre[0])
		 {
			 root = i;
			 break;
		 }
	 }
	 //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
	 //利用上述这点，对二叉树节点进行归并
	 for (int i = 0; i < root; i++)
	 {
		 left_pre.push_back(pre[i + 1]);//前序第一个为根节点
		 left_in.push_back(in[i]);
	 } 
	 for (int i = root + 1; i < length; i++)
	 {
		 right_pre.push_back(pre[i]);
		 right_in.push_back(in[i]);
	 }
	 //和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
	 //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	 head->left = reConstructBinaryTree(left_pre, left_in);
	 head->right = reConstructBinaryTree(right_pre, right_in);
	 return head;
 }
