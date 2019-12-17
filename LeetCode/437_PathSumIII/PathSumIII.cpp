// 解法一: 时间复杂度O(N), 空间复杂度O(N)， 由于递归; 时间复杂度:最好情况下为O(NlogN), 此时为平衡树



// 解法二: Dual DFS

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
