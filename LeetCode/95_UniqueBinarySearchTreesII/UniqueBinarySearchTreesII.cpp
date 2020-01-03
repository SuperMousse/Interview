 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 动态规划
// 已有节点{1, 2}, 加入新节点3
// 1. 新的节点作为根节点, newroot->left = oldroot
// 2. 新节点不是根节点, 遍历整个树, 如果当前节点有右子树, old node->right = new node; new olde->left = right child
//                   遍历达到树的末尾时, end node->right = new node
// 注意: clone和recover


  vector<TreeNode*> generateTrees(int n) {
      if(n <= 0) {
          return vector<TreeNode*>();
      }
      vector<TreeNode*> result(1, nullptr);
      // get dp[1] ~ dp[]
      for (int i = 1; i <= n; ++i) {
          vector<TreeNode*> temp;
          for (int j = 0; j < result.size(); ++j) {
              // new node as root node
              TreeNode* oldRoot = result[j];
              TreeNode* root = new TreeNode(i);
              TreeNode* cloneOldRoot = clone(oldRoot); // clone old root
              root->left = cloneOldRoot;
              temp.push_back(root);
              // new node is not root node
              if(oldRoot != nullptr) {
                  TreeNode* tempOld = oldRoot;
                  // if current node has a right child
                  while(tempOld->right != nullptr) {
                      TreeNode* nonRoot = new TreeNode(i); // i-th node
                      TreeNode* tempRight = tempOld->right;
                      tempOld->right = nonRoot; // insert i-th node
                      nonRoot->left = tempRight;
                      TreeNode* target = clone(oldRoot);
                      temp.push_back(target);
                      // restore the sub tree
                      tempOld->right = tempRight;
                      tempOld = tempOld->right; // 二叉搜索树一直寻找右子树即可找到最大的元素
                  }
                  // reach the end of the tree, tempOld->right==nullptr
                  // clone oldRoot and restore
                  tempOld->right = new TreeNode(i);
                  TreeNode* target = clone(oldRoot);
                  temp.push_back(target);
                  tempOld->right = nullptr;
              }
          }
          result = temp;
      }
      return result;
  }

  TreeNode* clone(TreeNode* root) {
      if(root == nullptr) {
          return nullptr;
      }
      TreeNode* newRoot = new TreeNode(root->val);
      newRoot->left = clone(root->left);
      newRoot->right = clone(root->right);
      return newRoot;
  }
