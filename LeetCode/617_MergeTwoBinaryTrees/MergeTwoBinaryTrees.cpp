
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
 if (t1 == nullptr || t2 == nullptr) {
   return t1 ? t1 : t2;
 }
 TreeNode* pNode = new TreeNode(t1->val + t2->val);
 pNode->left = mergeTrees(t1->left, t2->left);
 pNode->right = mergeTrees(t1->right, t2->right);
 return pNode;
}
