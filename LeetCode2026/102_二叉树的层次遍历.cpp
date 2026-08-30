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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            vector<int> layer;
            int currSize = queue.size(); // 当前层的size必须预先保留下来，如果使用queue.size()作为for循环里面判断
                                         // 会在插入元素后queue.size()变化导致出错
            for (int i = 0; i < currSize; i++) {
                TreeNode* pCurr = queue.front();
                queue.pop();
                layer.push_back(pCurr->val);
                if (pCurr->left != nullptr) {
                    queue.push(pCurr->left);
                }
                if (pCurr->right != nullptr) {
                    queue.push(pCurr->right);
                }
            }
            result.push_back(layer);
        }
        return result;
    }
};
