// 方法一： 二叉树层次遍历， 速度有点慢
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


// 指针沿着深度和水平两个方向直接移动
Node* connect(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* pPrev = root;
    Node* pCurr = nullptr;
    while(pPrev->left) {
        pCurr = pPrev;
        while (pCurr) {
            pCurr->left->next = pCurr->right;
            if (pCurr->next) {
                pCurr->right->next = pCurr->next->left;
            }
            pCurr = pCurr->next;
        }
        pPrev = pPrev->left;
    }
    return root;
}
