 /*
 1. If the longest path will include the root node, then the longest path must 
    be the depth(root->right) + depth (root->left)
 2. If the longest path does not include the root node, this problem is divided
    into 2 sub-problem: set left child and right child as the new root separately, 
	and repeat step1.
 */

 class Solution {
 public:
	 int diameterOfBinaryTree(TreeNode* root) {
		 if (root == nullptr) {
			 return 0;
		 }
		 int maxSum = 0;
		 diameterOfBinaryTreeCore(root, maxSum);
		 return maxSum;
	 }

	 // max depth
	 int diameterOfBinaryTreeCore(TreeNode* root, int& maxSum) {
		 if (root == nullptr) {
			 return 0;
		 }
		 int left = diameterOfBinaryTreeCore(root->left, maxSum);
		 int right = diameterOfBinaryTreeCore(root->right, maxSum);
		 maxSum = max(maxSum, left + right);
		 int depth = max(left, right) + 1;

		 return depth;
	 }

 };
