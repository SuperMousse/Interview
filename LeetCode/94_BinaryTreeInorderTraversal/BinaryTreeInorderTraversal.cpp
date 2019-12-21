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


// 非递归
