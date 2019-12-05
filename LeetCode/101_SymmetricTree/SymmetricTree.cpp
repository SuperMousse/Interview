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
bool isSymmetric(TreeNode* root) {
		 if (root == nullptr) {
			 return true;
		 }
		 stack<TreeNode*> stackTreeNode;
		 TreeNode* pNodeLeft = root;
		 TreeNode* pNodeRight = root;
		 stackTreeNode.push(pNodeLeft);
		 stackTreeNode.push(pNodeRight);
		 while (!stackTreeNode.empty()) {
			 pNodeLeft = stackTreeNode.top();
			 stackTreeNode.pop();
			 pNodeRight = stackTreeNode.top();
			 stackTreeNode.pop();
			 if (pNodeLeft == nullptr && pNodeRight == nullptr) {
				 continue;
			 }
			 if (pNodeLeft == nullptr || pNodeRight == nullptr) {
				 return false;
			 }

			 if (pNodeLeft->val != pNodeRight->val) {
				 return false;
			 }

			 stackTreeNode.push(pNodeLeft->left);
			 stackTreeNode.push(pNodeRight->right);
			 stackTreeNode.push(pNodeLeft->right);
			 stackTreeNode.push(pNodeRight->left);
		 }

		 return true;
	 }
