// 递归自底向上
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
   
  // 非递归
