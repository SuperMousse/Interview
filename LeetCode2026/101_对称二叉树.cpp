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
    bool core(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return core(root1->left, root2->right) && core(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return core(root, root);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> queue;
        TreeNode* pLeft = root->left;
        TreeNode* pRight = root->right;
        queue.push(pLeft);
        queue.push(pRight);
        while (!queue.empty()) {
            pLeft = queue.front();
            queue.pop();
            pRight = queue.front();
            queue.pop();
            if (pLeft == nullptr && pRight == nullptr) {
                continue;
            }
            if (pLeft == nullptr || pRight == nullptr) {
                return false;
            }
            if (pLeft->val != pRight->val) {
                return false;
            }
            queue.push(pLeft->left);
            queue.push(pRight->right);
            queue.push(pLeft->right);
            queue.push(pRight->left);
        }
        return true;
    }
};
