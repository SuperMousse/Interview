// 递归 
vector<int> inorderTraversal(TreeNode* root) {
   vector<int> result;
   if (root == nullptr) {
     return result;
   }
   helper(root, result);
   return result;
 }

 void helper(TreeNode* root, vector<int>& result) {
   if (root == nullptr) {
     return;
   }
   if (root->left != nullptr) {
     helper(root->left, result);
   }
   result.push_back(root->val);
   if (root->right != nullptr) {
     helper(root->right, result);
   }
   return;
 }


// 非递归中序遍历
 class Solution {
 public:
	 vector<int> inorderTraversal(TreeNode* root) {
		 vector<int> result;
		 if (root == nullptr) {
			 return result;
		 }
		 stack<TreeNode*> stackTreeNode;
		 TreeNode* pNode = root;
		 while (pNode != nullptr || !stackTreeNode.empty()) {
			 while (pNode != nullptr) {
				 stackTreeNode.push(pNode);
				 pNode = pNode->left;
			 }
			 if (!stackTreeNode.empty()) {
				 pNode = stackTreeNode.top();
				 stackTreeNode.pop();
				 result.push_back(pNode->val);
				 pNode = pNode->right;
			 }
		 }
		 return result;
	 }
 };

// 非递归先序遍历


// 非递归后续遍历
