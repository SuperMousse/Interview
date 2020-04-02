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
vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return vector<int>();
    }
    vector<int> result;
    stack<TreeNode*> stackTree;
    TreeNode* pNode = root;
    stackTree.push(pNode);
    while (!stackTree.empty()) {
        pNode = stackTree.top();
        stackTree.pop();
        result.push_back(pNode->val);
        if (pNode->left != nullptr) {
            stackTree.push(pNode->left);
        }
        if (pNode->right != nullptr) {
            stackTree.push(pNode->right);
        }
    }
    return result;
}

// 非递归后序遍历
// 解法一: 根据后序遍历 左 -> 右 -> 根, 按照先序遍历的写法, 根 -> 右 -> 左, 然后再reverse
// 非递归先序遍历
vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return vector<int>();
    }
    vector<int> result;
    stack<TreeNode*> stackTree;
    TreeNode* pNode = root;
    stackTree.push(pNode);
    while (!stackTree.empty()) {
        pNode = stackTree.top();
        stackTree.pop();
        result.push_back(pNode->val);
	if (pNode->right != nullptr) {
            stackTree.push(pNode->right);
        }
        if (pNode->left != nullptr) {
            stackTree.push(pNode->left);
        }

    }
	
    reverse(result.begin(), result.end());
    return result;
}
