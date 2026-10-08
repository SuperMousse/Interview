/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 如果左子树含有p，右子树含有q，那么当前节点即为祖先；反之亦然
    // 如果当前遍历到某个节点x，且q位于x的子树中，则当前节点x为p的祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 返回nullptr, 这个子树里面没有p/q; 返回p/q，说明找到了一个; 返回其他节点：说明节点是p/q的公共祖先
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* pLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* pRight = lowestCommonAncestor(root->right, p, q);
        // 左侧子树中没有p/q, p/q只能在右子树里面
        if (pLeft == nullptr) {
            return pRight;
        }
        else if (pRight == nullptr) {
            return pLeft;
        }
        else {
            return root; // 左右子树都找到了p/q; 如果左子树有p，右子树有q，且都不是nullptr，那么当前节点为祖先
        }
    }
};
