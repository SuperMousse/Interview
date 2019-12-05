// 递归 
bool isSymmetric(TreeNode* root) {
		 return isSymmetricCore(root, root);
	 }

	 bool isSymmetricCore(TreeNode* left, TreeNode* right) {
		 if (left == nullptr && right == nullptr) {
			 return true;
		 }
		 if (left == nullptr || right == nullptr) {
			 return false;
		 }
		 if (left->val != right->val) {
			 return false;
		 }
		 return isSymmetricCore(left->left, right->right) && isSymmetricCore(left->right, right->left);
	 }


// 非递归
