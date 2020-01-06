    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
			 return vector<vector<int> >();
		 }
		 vector<vector<int> > result;
		 TreeNode* pNode = root;
		 queue<TreeNode*> queueTreeNode;
		 queueTreeNode.push(root);
		 while (!queueTreeNode.empty()) {
			 int length = queueTreeNode.size();
			 vector<int> temp;
			 for (int i = 0; i < length; ++i) {
				 pNode = queueTreeNode.front();
				 queueTreeNode.pop();
				 if (pNode != nullptr) {
					 temp.push_back(pNode->val);
				 }
				 if (pNode->left != nullptr) {
					 queueTreeNode.push(pNode->left);
				 }
				 if (pNode->right != nullptr) {
					 queueTreeNode.push(pNode->right);
				 }
			 }
			 result.push_back(temp);
		 }

		 reverse(result.begin(), result.end());
		 return result;
    }
