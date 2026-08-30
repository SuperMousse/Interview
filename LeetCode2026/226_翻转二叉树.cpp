/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* pLeft = nullptr;
        TreeNode* pRight = nullptr;
        while(!queue.empty()) {
            TreeNode* pCurr = queue.front();
            queue.pop();
            pLeft = pCurr->left;
            pRight = pCurr->right;
            pCurr->left = pRight;
            pCurr->right = pLeft;
            if (pLeft != nullptr) {
                queue.push(pLeft);
            }
            if (pRight != nullptr) {
                queue.push(pRight);
            }
        }
        return root;
    }
};

