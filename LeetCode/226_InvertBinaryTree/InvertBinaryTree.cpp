// 递归自底向上, 后序
	 TreeNode* invertTree(TreeNode* root) {
		 if (root == nullptr) {
			 return nullptr;
		 }

		 if (root->left != nullptr) {
			 invertTree(root->left);
		 }
		 if (root->right != nullptr) {
			 invertTree(root->right);
		 }

		 TreeNode* temp = root->left;
		 root->left = root->right;
		 root->right = temp;
		 return root;
	 }
   
  // 非递归, 先序
	 TreeNode* invertTree(TreeNode* root) {
		 if (root == nullptr) {
			 return nullptr;
		 }

		 stack<TreeNode*> stackTreeNode;
		 stackTreeNode.push(root);
		 while (!stackTreeNode.empty()) {
			 TreeNode* pNode = stackTreeNode.top();
			 stackTreeNode.pop();
			 if (pNode != nullptr) {
				 stackTreeNode.push(pNode->left);
				 stackTreeNode.push(pNode->right);
				 TreeNode* temp = pNode->left;
				 pNode->left = pNode->right;
				 pNode->right = temp;
			 }
		 }

		 return root;
	 }
