
 // 回溯法
 vector<string> generateParenthesis(int n) {
   vector<string> result;
   if (n <= 0) {
     return result;
   }
   generateParenthesisCore(n, result, "", 0, 0);
   return result;
 }

 void generateParenthesisCore(int n, vector<string>& result, string str, int open, int close) {
   if (str.size() == 2 * n) {
     result.push_back(str);
     return;
   }
   if (open < n) {
     generateParenthesisCore(n, result, str + "(", open + 1, close);
   }
   if (close < open) {
     generateParenthesisCore(n, result, str + ")", open, close + 1);
   }
   return;
 }
 
