vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return vector<int>();
    }
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* pNode = st.top();
        st.pop();
        res.push_back(pNode->val);
        if (pNode->right != nullptr) {
            st.push(pNode->right);
        }
        if (pNode->left != nullptr) {
            st.push(pNode->left);
        }
    }
    return res;
}
