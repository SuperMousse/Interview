struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 深度优先
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr) {
		return 0;
	}
	int nLeft = TreeDepth(pRoot->left);
	int nRight = TreeDepth(pRoot->right);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}


// 广度优先

 int maxDepth(TreeNode* root)
	 {
		 if (root == nullptr)
			 return 0;

		 int res = 0;
		 queue<TreeNode*> queueTreeNode;
		 queueTreeNode.push(root);
		 while (!queueTreeNode.empty())
		 {
			 ++res;
			 for (int i = 0, n = queueTreeNode.size(); i < n; ++i)
			 {
				 TreeNode* pNode = queueTreeNode.front();
				 queueTreeNode.pop();

				 if (pNode->left != nullptr)
					 queueTreeNode.push(pNode->left);
				 if (pNode->right != nullptr)
					 queueTreeNode.push(pNode->right);
			 }
		 }

		 return res;
	 }

// 树的最小深度
