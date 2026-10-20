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
    bool core(TreeNode* root, int& depth) {
        if (root == nullptr) {
            return true;
        }
        int left = 0;
        int right = 0;
        if(core(root->left, left) && core(root->right, right)) {
            int diff = abs(left - right);
            if (diff <= 1) {
                depth = max(left, right) + 1;
                return true;
            }
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int depth = 0;
        return core(root, depth);
    }
};
