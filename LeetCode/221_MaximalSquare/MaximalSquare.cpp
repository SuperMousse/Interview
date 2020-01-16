// 动态规划
// dp[i][j]表示以i,j为右下角的最大的正方形的边长是多少
// dp[i][j]的左侧、上侧、左上侧的最小值为a, 则i,j处构成的正方形边长为a+1
// dp[i][j] = min(dp[左侧], dp[上侧], dp[左上侧]) + 1

 int maximalSquare(vector<vector<char>>& matrix) {
   if (matrix.empty()) {
     return 0;
   }
   int rows = matrix.size();
   int cols = matrix[0].size();
   int maxEdge = 0;
   vector<vector<int> > dp(rows, vector<int>(cols, 0));
   for (int i = 0; i < rows; ++i){
     for (int j = 0; j < cols; ++j) {
       if (matrix[i][j] == '1') {
         int left = j > 0 ? dp[i][j - 1] : 0;
         int up = i > 0 ? dp[i - 1][j] : 0;
         int leftUp = (i > 0 && j > 0 ) ? dp[i - 1][j - 1] : 0;
         dp[i][j] = min(min(left, up), leftUp) + 1;
         maxEdge = max(maxEdge, dp[i][j]);
       }
     }
   }
   return maxEdge * maxEdge;
 }
