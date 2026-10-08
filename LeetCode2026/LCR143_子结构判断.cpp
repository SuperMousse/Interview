/*
给定两棵二叉树 tree1 和 tree2，判断 tree2 是否以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。
注意，空树 不会是以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。
*/
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
    bool isSameTree(TreeNode* A, TreeNode* B) {
        // B 已经匹配完毕
        if (B == nullptr) {
            return true;
        }
        // B 还未匹配完，但 A 已经结束
        if (A == nullptr) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr || A == nullptr) {
            return false;
        }
        if (isSameTree(A, B)) {
            return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
