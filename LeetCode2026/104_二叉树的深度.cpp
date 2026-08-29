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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return (left_depth > right_depth) ? (left_depth+1) : (right_depth+1);

    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> queueTree;
        queueTree.push(root);
        while(!queueTree.empty()) {
            ++depth;
            for (int i = 0, n = queueTree.size(); i < n; i++) {
                TreeNode *pNode = queueTree.front();
                queueTree.pop();
                if (pNode->left != nullptr) {
                    queueTree.push(pNode->left);
                }
                if (pNode->right != nullptr) {
                    queueTree.push(pNode->right);
                }
            }
        }
        return depth;
    }
};
