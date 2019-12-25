vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int> > result;
    if(k <= 0 || n <= 0){
        return result;
    }
    vector<int> combination;
    helper(k, n, result, combination, 1);
    
    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return result;
}

void helper(int k, int n, vector<vector<int> >& result, vector<int>& combination, int begin) {
    if(n == 0 && combination.size() == k) {
        result.push_back(combination);
        return;
    }
    for (int i = begin; i < 10 && n >= i; ++i) {
        combination.push_back(i);
        helper(k, n - i, result, combination, i + 1);
        combination.pop_back();
    }
}
