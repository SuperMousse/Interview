vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    if(candidates.empty()){
        return result;
    }
    sort(candidates.begin(), candidates.end());
    vector<int> combination;
    helper(candidates, target, result, combination, 0);
    
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    
    return result;
}

void helper(vector<int>& candidates, int target,
            vector<vector<int> >& result, vector<int> combination, int begin){
    if(target == 0){
        result.push_back(combination);
        return;
    }
    for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
        // 数组中可能会有重复元素, 这样重复元素跟后面的元素就会组成多种组合
        if(i == begin || candidates[i] != candidates[i-1]){
            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();
        }
    }
    return;
}
