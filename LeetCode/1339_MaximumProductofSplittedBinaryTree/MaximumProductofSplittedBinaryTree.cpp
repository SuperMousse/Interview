// 输入一棵二叉树, 移除二叉树上的一条边, 计算两棵子树的节点之和, 使得两棵子树的节点和乘积最大
// 分析: 想要把二叉树拆成两棵树, 可以进行遍历, 在遍历过程中计算当前节点上所有子节点的和,
// 树所有节点的和 - 当前节点的所有子节点的和 = 剩余节点的和
// result = max(result, 当前节点所有子节点的和 * 剩余节点的和)
// 因此, 需要两次遍历, 第一次计算totalSum, 第二次计算maxProduct

class Solution {
public:
    int maxProduct(TreeNode *root) {
        long long maxProduct = 0;
        long long totalSum = 0;
        long long subSum = 0; // 当前节点
        totalSum = maxProductCore(root, maxProduct, totalSum, subSum);
        // 运行两次的原因是因为第一次totalSum的值并不是正确的, 进行了一次遍历之后totalSum的值才是真正的totalSum
        maxProductCore(root, maxProduct, totalSum, subSum);
        return maxProduct % 1000000007;
    }

    long long maxProductCore(TreeNode* root, long long& maxProduct, long long& totalSum, long long& subSum) {
        if (root == nullptr) {
            return 0;
        }
        // 当前节点及其子树的和
        subSum = root->val +
                 maxProductCore(root->left, maxProduct, totalSum, subSum) +
                 maxProductCore(root->right, maxProduct, totalSum, subSum);
        // 最大乘积 = 当前节点及其子节点的和 * 剩余节点的和 = subSum * (totalSum - subSum);
        maxProduct = max(maxProduct, subSum * (totalSum - subSum));
        return subSum;
    }
};
