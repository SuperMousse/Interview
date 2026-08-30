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
    int core(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = core(root->left, result); // 左子树为根的子树深度，即节点数
        int rightDepth = core(root->right, result);
        result = max(result, leftDepth + rightDepth + 1); // 计算节点数
        return max(leftDepth, rightDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // 两个节点之间最长的路径 = 节点左子树节点数 + 右字数节点数 - 1
        int result = 1;
        core(root, result);
        return result - 1; // 节点数-1为边数
    }
};
