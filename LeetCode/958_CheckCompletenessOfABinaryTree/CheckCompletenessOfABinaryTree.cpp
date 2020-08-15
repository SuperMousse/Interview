
// 给定一棵二叉树, 检查它是否是完全二叉树,
// 满二叉树: 二叉树每层节点都达到最大值, 层数为k, 则节点个数为(2^k) -1
// 完全二叉树: 二叉树中的节点自上至下, 自左向右编号, 编号为i的节点与满二叉树中编号为i的节点在
//           二叉树中位置相同, 也就是除了最后一层的节点外, 每一层节点都是满的, 并且最后一层
//           的节点尽可能靠左, 最后一层节点数目在1~(2^(k-1))之间

// 二叉树层次遍历, 对于满二叉树来说, 遇到第一个空节点之后, 后续不存在任何节点
bool isCompleteTree(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    bool seeEmpty = false;
    queue<TreeNode*> queueTreeNode;
    queueTreeNode.push(root);
    while (!queueTreeNode.empty()) {
        TreeNode* pNode = queueTreeNode.front();
        queueTreeNode.pop();
        if (pNode == nullptr) {
            seeEmpty = true;
            continue;
        }
        else {
            if (seeEmpty == true) {
                return false;  // 如果遇到了一个空节点之后, 后面不应该再出现任何非空节点
            }
        }
        queueTreeNode.push(pNode->left);
        queueTreeNode.push(pNode->right);
    }
    return true;
}
