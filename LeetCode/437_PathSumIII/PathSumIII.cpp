// 解法一: 时间复杂度O(N)
int pathSum(TreeNode* root, int sum) {
     if (root == nullptr) {
         return 0;
     }
     int pathCount = 0;
     int pathSum = 0;
     unordered_map<int, int> preSum;
     preSum[0] = 1;

     pathSumCore(root, sum, pathCount, pathSum, preSum);

     return pathCount;
}

 // pathSum不使用引用
void pathSumCore(TreeNode* root, int sum, int& pathCount, int pathSum, unordered_map<int, int>& preSum) {
     if (root == nullptr) {
         return;
     }
     // update the path sum by adding the current val
     pathSum += root->val;

     // The sum from any node in the middle of the path to the current node = 
     // the sum from the root to the current node - the prefix path sum of the node in the middle.
     if (preSum.count(pathSum - sum) == 1) {
         pathCount += preSum[pathSum - sum];
     }

     // update the map with the current sum, so the map is good to be passed to the next recursion
     ++preSum[pathSum];

     pathSumCore(root->left, sum, pathCount, pathSum, preSum);
     pathSumCore(root->right, sum, pathCount, pathSum, preSum);

     // restore the map, as the recursion goes from the bottom to the top
     --preSum[pathSum];

     return;
}



// 解法二: Dual DFS, 空间复杂度O(N)， 由于递归; 时间复杂度:最好情况下为O(NlogN), 此时为平衡树

public int pathSum(TreeNode root, int sum) {
    if (root == null)
      return 0;
    return dfs(root, sum, 0) + pathSum(root.left, sum) + pathSum(root.right, sum);
  }

  private int dfs(TreeNode root, int sum, int cur) {
    if (root == null)
      return 0;
    cur += root.val;
    return (cur == sum ? 1 : 0) + dfs(root.left, sum, cur) + dfs(root.right, sum, cur);
  }
