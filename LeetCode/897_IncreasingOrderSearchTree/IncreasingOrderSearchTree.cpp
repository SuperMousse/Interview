  TreeNode* increasingBST(TreeNode* root) {
      if (!root) {
          return nullptr;
      }
      return dfs(root, nullptr);
  }

  TreeNode* dfs(TreeNode* root, TreeNode* tail) {
      if (!root) {
          return tail;
      }
      TreeNode* res = dfs(root->left, root);
      root->left = nullptr;
      root->right = dfs(root->right, tail);
      return res;
  }
