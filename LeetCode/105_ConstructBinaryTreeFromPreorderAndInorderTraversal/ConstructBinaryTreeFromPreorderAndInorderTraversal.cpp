	 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		 if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
			 return nullptr;
		 }
		 int length = preorder.size();
		 TreeNode* head = helper(preorder, inorder, 0, length - 1, 0, length - 1);
		 return head;
	 }

	 TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int beginPre, int endPre,
		              int beginIn, int endIn) {
		 int rootVal = preorder[beginPre];
		 TreeNode* root = new TreeNode(rootVal);
		 root->left = root->right = nullptr;
		 if (beginPre == endPre) {
			 if (preorder[beginPre] == preorder[endPre]) {
				 return root;
			 }
			 else {
				 throw runtime_error("Invalid Input");
			 }
		 }

		 int rootInIndex = beginIn;
		 while (rootInIndex <= endIn && inorder[rootInIndex] != rootVal) {
			 ++rootInIndex;
		 }
		 if (rootInIndex == endIn && inorder[rootInIndex] != inorder[endIn]) {
			 throw runtime_error("Invalid Input");
		 }
		 int leftLength = rootInIndex - beginIn;
		 int leftEndPre = beginPre + leftLength;

		 if (leftLength > 0) {
			 root->left = helper(preorder, inorder, beginPre + 1, leftEndPre, beginIn, rootInIndex - 1);
		 }
		 // endPre - beginPre为preorder中去掉根节点的元素个数
		 // 只有leftLength < (endPre - beginPre)时才存在右子树，否则不存在右子树
		 if (leftLength < (endPre - beginPre)) {
			 root->right = helper(preorder, inorder, leftEndPre + 1, endPre, rootInIndex + 1, endIn);
		 }
		 return root;
	 }
