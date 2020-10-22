class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        if (n < 1) {
            return result;
        }

        vector<int> subCombination;
        combinationCore(result, subCombination, n, k, 1);

        // sort(result.begin(), result.end());

        return result;
    }
    
    void combinationCore(vector<vector<int> >& result, vector<int>& subCombination,
                     int n, int k, int begin) {
        if (k == 0) {
            result.push_back(subCombination);
            return;
        }
        // n - i + 1 >= k, 要求i之后的数字个数要大于等于k个
        for (int i = begin; n - i + 1 >= k; ++i) { // 从前向后依次选取
            subCombination.push_back(i);
            combinationCore(result, subCombination, n, k - 1, i + 1);
            subCombination.pop_back();
        }
        return;
    }

};
