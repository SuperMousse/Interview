 // 解法一
 /*
return an array of two elements, the first element of which denotes the maximum amount
of money that can be robbed if root is not robbed, while the second element signifies
the maximum amount of money robbed if it is robbed.
*/

// 不使用当前根节点, result[0] = 左子树的result最大值 + 右子树的result最大值
// 使用当前根节点, result[1] = 根节点 + 左右子树的result[0]

 int rob(TreeNode* root) {
   if (root == nullptr) {
     return 0;
   }
   vector<int> result(2, 0);
   result = helper(root);
   return max(result[0], result[1]);
 }

 vector<int> helper(TreeNode* root) {
   if (root == nullptr) {
     return;
   }
   vector<int> left = helper(root->left);
   vector<int> right = helper(root->right);
   vector<int> result(2, 0);
   result[0] = max(left[0], left[1]) + max(right[0], right[1]);
   result[1] = root->val + left[0] + right[0];
 }
 
 // 解法二: 带记忆的动态规划(递归)
 class Solution {
 public:
	 int rob(TreeNode* root) {
		 if (root == nullptr) {
			 return 0;
		 }
		 unordered_map<TreeNode*, int> hashTreeNode;
		 int result = helper(root, hashTreeNode);
		 return result;
	 }

	 int helper(TreeNode* root, unordered_map<TreeNode*, int>& hash) {
		 if (root == nullptr) {
			 return 0;
		 }
		 if (hash.count(root) != 0) {
			 return hash[root];
		 }
		 int val = 0;
		 if (root->left != nullptr) {
			 val += helper(root->left->left, hash) + helper(root->left->right, hash);
		 }
		 if (root->right != nullptr) {
			 val += helper(root->right->left, hash) + helper(root->right->right, hash);
		 }
		 int notUseRoot = root->val + val;
		 int useRoot = helper(root->left, hash) + helper(root->right, hash);
		 val = max(notUseRoot, useRoot);
	     hash[root] = val;
		 return val;
	 }
 };
