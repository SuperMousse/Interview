Node* connect(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    queue<Node*> queueNode;
    queueNode.push(root);
    while(!queueNode.empty()) {
        int n = queueNode.size();
        for (int i = 0; i < n; ++i) {
            Node* pNode = queueNode.front();
            queueNode.pop();
            if (queueNode.size() > 0 && (i != n - 1)) {
                pNode->next = queueNode.front();
            }
            else {
                pNode->next = nullptr;
            }
            if (pNode->left) {
                queueNode.push(pNode->left);
            }
            if (pNode->right) {
                queueNode.push(pNode->right);
            }
        }
    }
    return root;
}
