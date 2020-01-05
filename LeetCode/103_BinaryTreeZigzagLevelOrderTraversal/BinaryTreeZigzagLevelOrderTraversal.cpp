	 vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		 if (root == nullptr) {
			 return vector<vector<int> >();
		 }
		 vector<vector<int> > result;
		 TreeNode* pNode = nullptr;
		 int current = 0;
		 stack<TreeNode*> stackTreeNode[2];
		 stackTreeNode[current].push(root);
		 while (!stackTreeNode[current].empty() || !stackTreeNode[1 - current].empty()) {
			 int length = stackTreeNode[current].size();
			 vector<int> temp;
			 for (int i = 0; i < length; i++) {
				 pNode = stackTreeNode[current].top();
				 stackTreeNode[current].pop();
				 temp.push_back(pNode->val);
				 if (current == 0) {
					 if (pNode->left != nullptr) {
						 stackTreeNode[1 - current].push(pNode->left);
					 }
					 if (pNode->right != nullptr) {
						 stackTreeNode[1 - current].push(pNode->right);
					 }
				 }
				 else {
					 if (pNode->right != nullptr) {
						 stackTreeNode[1 - current].push(pNode->right);
					 }
					 if (pNode->left != nullptr) {
						 stackTreeNode[1 - current].push(pNode->left);
					 }
				 }

			 }
			 result.push_back(temp);
			 current = 1 - current;
		 }
		 return result;
	 }
